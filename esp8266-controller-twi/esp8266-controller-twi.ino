#include "Config.h"

//--------------------------------------

#include <Arduino.h>

#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

#include <EEPROM.h>

#include <Wire.h>

#include "WiFiUtil.h"
#include "EEUtil.h"
#include "SerialOS.h"
#include "Util.h"
#include "TWIUtil.h"

//=============================================================
// SETUP
//=============================================================

void setup()
{
  Serial.println("Setup serial");
  Serial.begin(SERIAL_SPEED);
  //  Serial.swap(); // use D8(TX) - D7(RX)

  while (Serial.available())
    Serial.read();

  EEInit();

  Wire.begin(); // join i2c bus as master

  reconnectWifi();

Serial.print("TWI Bus devices : ");
  auto lst = TWIScan();
  auto n = lst.GetNode(0);
  while (n)
  {
    Serial.printf("0x%02x ", n->data);
    n = n->next;
  }
  Serial.println();
}

//=============================================================
// LOOP
//=============================================================

void loop()
{

  manageWifi();

  if (Serial.available())
  {
    auto c = (char)Serial.read();
    if ((int)c != 255)
    {
      if (c == '?' && serialInput.length() == 0)
        printSyntaxHelp();
      else if (c == '\r')
        processSerialCmd();
      else if (c == 8) // backspace
        serialInput.remove(serialInput.length() - 1);
      else
        serialInput.concat(c);
    }
  }

  if (server.status() == CLOSED)
    return;
}
