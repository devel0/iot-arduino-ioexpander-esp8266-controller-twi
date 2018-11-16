#include "WiFiUtil.h"
#include "EEUtil.h"
#include "SerialOS.h"

WiFiServer server(WEB_PORT);

//
void reconnectWifi()
{
  if (server.status() != CLOSED)
    server.stop();

  String ssid = "";
  String pass = "";

  readWifiSSID(ssid);
  readWifiPWD(pass);

  Serial.printf("Trying connecting SSID:[%s]\n", ssid.c_str());

  WiFi.begin(ssid.c_str(), pass.c_str());

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true)
      ;
  }

  Serial.println("Connecting WiFi ( press CTRL+C to stop )");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print('.');
    if (Serial.available() && Serial.read() == 3)
    {
      printSyntaxHelp();
      return;
    }
  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");
  printCurrentNet();
  printWifiData();

  Serial.println("Type ? for commands");
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LOW);

  server.begin();
}

#define CCTYPE_HTML 0
#define CCTYPE_JSON 1
#define CCTYPE_TEXT 2
#define CCTYPE_JS 3

void clientOk(WiFiClient &client, int type)
{
  client.println("HTTP/1.1 200 OK");
  switch (type)
  {
  case CCTYPE_HTML:
    client.println("Content-Type: text/html");
    break;

  case CCTYPE_JSON:
    client.println("Content-Type: application/json");
    break;

  case CCTYPE_TEXT:
    client.println("Content-Type: text/plain");
    break;

  case CCTYPE_JS:
    client.println("Content-Type: text/javascript");
    break;
  }

#if ENABLE_CORS == 1
  client.println("Access-Control-Allow-Origin: *");
#endif

  client.println();
}

// buffered writing of string
void clientWriteBigString(WiFiClient& client, const char *str)
{
  char buf[81];
  auto l = strlen(str);
  for (int i = 0; i < l; i += 80)
  {
    auto s = 80;
    if (i + 80 > l)
      s = l - i;
    strncpy(buf, str + i, s);
    buf[s] = 0;
    client.print(buf);
  }
}

String header;

//
void manageWifi()
{
  WiFiClient client = server.available();

  if (client)
  {
    String currentLine = "";

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        header += c;
        Serial.printf("header [%s]\n", header.c_str());

        if (c == '\n')
        {
          if (header.indexOf("GET / ") >= 0 || header.indexOf("GET /index.htm") >= 0)
          {
            clientOk(client, CCTYPE_HTML);

            const char *str =
#include "index.htm.h"
                ;

            clientWriteBigString(client, str);
          }

          header = "";
          break;
        }
      }
    }

    client.stop();
  }
}

//
void printWifiData()
{
  auto ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  for (int i = 0; i < 6; ++i)
  {
    Serial.print(mac[i], HEX);
    if (i != 5)
      Serial.print(":");
    else
      Serial.println();
  }
}

//
void printCurrentNet()
{
  Serial.printf("SSID: %s\n", WiFi.SSID().c_str());

  auto bssid = WiFi.BSSID();
  Serial.print("BSSID: ");
  for (int i = 0; i < 6; ++i)
  {
    Serial.print(bssid[i], HEX);
    if (i != 5)
      Serial.print(":");
    else
      Serial.println();
  }

  auto rssi = WiFi.RSSI();
  Serial.printf("signal strength (RSSI): %ld\n", rssi);
}