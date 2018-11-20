#include <Arduino.h>
#include <Wire.h>

#include "Util.h"

#include "Config.h"

// current twi command
#define CMD_NONE 0
#define CMD_GETPORTMODE 1
#define CMD_SETPORTMODE 2
#define CMD_GETPORTVALUE 3
#define CMD_SETPORTVALUE 4

//------------------------------------------------------------
// SETUP
//------------------------------------------------------------
void setup()
{

  Serial.begin(115200);  
  Serial.println("SETUP");

  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Wire.begin(TWI_ADDRESS); // join bus as slave
}

long m = millis();

//------------------------------------------------------------
// LOOP
//------------------------------------------------------------
void loop()
{
  if (TimeDiff(m, millis()) > 500)
  {
    m = millis();
  }
}

char buf[40];

int cmdRegister = CMD_NONE;
int qport = 0;
int qportval = 0;
int qportmode = 0;

//------------------------------------------------------------
// MASTER REQUEST INFO
//------------------------------------------------------------
void requestEvent()
{
  unsigned long mfrom = micros();

  switch (cmdRegister)
  {

  case CMD_GETPORTMODE:
  {
    auto res = getPinMode(qport);
    auto ww = Wire.write(res);
  }
  break;

  case CMD_GETPORTVALUE:
  {
    auto res = digitalRead(qport);
    auto ww = Wire.write(res);
  }
  break;

  default:
    Serial.println("Unknown current command");
    break;
  }
  long timediff = TimeDiff(mfrom, micros());
  Serial.print("Took ");
  Serial.print(timediff);
  Serial.println(" us");
}

//------------------------------------------------------------
// RECEIVE FROM MASTER
//------------------------------------------------------------
void receiveEvent(int howMany)
{
  String cmd;
  while (Wire.available() > 0)
  {
    auto c = (int)Wire.read();
    cmd.concat((char)c);
  }
  Serial.print("CMD=");
  Serial.println(cmd);

  //
  // getportmode <portstr>
  if (cmd.indexOf("getportmode ") >= 0)
  {
    cmdRegister = CMD_GETPORTMODE;
    auto portstr = cmd.substring(12);
    qport = arduinoPortStrToNr(portstr.c_str());
  }
  //
  // setportmode <portstr> <mode>
  else if (cmd.indexOf("setportmode ") >= 0)
  {
    cmdRegister = CMD_SETPORTMODE;
    auto qq = cmd.substring(12);
    auto spacepos = qq.indexOf(" ");    
    auto portstr = qq.substring(0, spacepos);
    auto modestr = qq.substring(spacepos + 1);
    Serial.print("portstr = ");
    Serial.println(portstr);
    Serial.print("modestr = ");
    Serial.println(modestr);
    qport = arduinoPortStrToNr(portstr.c_str());
    qportmode = atoi(modestr.c_str());

    switch (qportmode)
    {
    case INPUT:
    case OUTPUT:
    case INPUT_PULLUP:
      Serial.print("setportmode ");
      Serial.print(qport);
      Serial.print(" ");
      Serial.println(qportmode);
      //pinMode(qport, qportmode);
      break;
    }
  }
  //
  // getportvalue <portstr>
  else if (cmd.indexOf("getportvalue ") >= 0)
  {
    cmdRegister = CMD_GETPORTVALUE;
    auto portstr = cmd.substring(13);
    qport = arduinoPortStrToNr(portstr.c_str());
  }
  //
  // setportvalue <portstr> <value>
  else if (cmd.indexOf("setportvalue ") >= 0)
  {
    cmdRegister = CMD_SETPORTVALUE;
    auto qq = cmd.substring(13);
    auto spacepos = qq.indexOf(" ");
    auto portstr = qq.substring(0, spacepos);
    auto valstr = qq.substring(spacepos + 1);
    qport = arduinoPortStrToNr(portstr.c_str());
    qportval = atoi(valstr.c_str());

    Serial.print("setportvalue ");
    Serial.print(qport);
    Serial.print(" ");
    Serial.println(qportval);
    digitalWrite(qport, qportval);
  }
}