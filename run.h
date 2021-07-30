#include "tools.h"
#include "temperature.h"
#include "addresses.h"

boolean Power = false;

boolean PowerButtonLast = false;
boolean ProgramButtonLast = false;

byte Program = 0;

void SetPowerState()
{
  boolean PowerButton = !digitalRead(10);
  if (checkButtonState(PowerButton, PowerButtonLast))
  {
    Power = !Power;
  }
  PowerButtonLast = PowerButton;
}

void SetProgramState()
{
  boolean ProgramButton = !digitalRead(9);
  if (checkButtonState(ProgramButton, ProgramButtonLast))
  {
    Program += 1;
  }
  //ProgramButtonLast = ProgramButton;
Serial.print("Program: "); Serial.println(Program);
  
  if (Program > 11)
  {
    Program = 0;
  }

 // Serial.print("Current button: ");
 // if (ProgramButton) Serial.println("true");
 // else Serial.println("false");
 // Serial.print("Last button: ");
 // if (ProgramButtonLast) Serial.println("true");
 // else Serial.println("false");
}

void setP1HighOn()
{
  TurnOff(Pump1);
  delayer(0, 1);
  TurnOn(Pump1High);
  delayer(0, 1);
  TurnOn(Pump1);
}

void setP1HighOff()
{
  TurnOff(Pump1);
  delayer(0, 1);
  TurnOff(Pump1High);
  delayer(0, 1);
}

void SetOutputs(byte program)
{
  boolean P1H = checkBit(program, 3);
  boolean P1 = checkBit(program, 2);
  boolean P2 = checkBit(program, 1);
  boolean B = checkBit(program, 0);

  Serial.println("H 1 2 B");
  if (P1H) Serial.print("1 ");
  else Serial.print("0 ");
  if (P1) Serial.print("1 ");
  else Serial.print("0 ");
  if (P2) Serial.print("1 ");
  else Serial.print("0 ");
  if (B) Serial.println("1 ");
  else Serial.println("0 ");
  
  if (P2)
  {
    TurnOn(Pump2);
  }
  if (!P2)
  {
    TurnOff(Pump2);
  }

  if (B)
  {
    TurnOn(Blower);
  }
  if (!B)
  {
    TurnOff(Blower);
  }
  
  if (!P1)
  {
    TurnOff(Pump1);
  }

  if (P1H)
  {
    setP1HighOn();
  }
  if (!P1H)
  {
    setP1HighOff();
  }

  if (P1)
  {
    TurnOn(Pump1);
  }
}

void run()
{
  controlTemperature();
  SetPowerState();
  SetProgramState();

  SetOutputs(Program);
  delayer(0, 5);
}
