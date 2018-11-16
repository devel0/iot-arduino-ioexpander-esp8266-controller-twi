#include <Arduino.h>
#include <Wire.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("SETUP");

  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Wire.begin(8); // join bus as slave
}

void loop()
{
  
}

char buf[40];

void requestEvent()
{
  Serial.println("REQUEST");
}

void receiveEvent(int howMany)
{
  Serial.print(".");
  //int i = 0;
  //buf[0] = 0;
  while (Wire.available() > 0)
  {
    auto c = (int)Wire.read();
    /*if (c == '\n')
      buf[i] = 0;
    else
      buf[i] = (char)Wire.read();
    ++i;*/
    Serial.print((char)c);
  }
  //Serial.println(buf);
}