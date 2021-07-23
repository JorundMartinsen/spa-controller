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
}

void SetProgramState()
{
  boolean ProgramButton = !digitalRead(9);
  if (checkButtonState(ProgramButton, ProgramButtonLast))
  {
    Program += 1;
  }
  if (Program > 11)
  {
    Program = 0;
  }
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
  TurnOn(Pump1High);
  delayer(0, 1);
}

void SetOutputs(byte program)
{
  boolean P1H = checkBit(program, 3);
  boolean P1 = checkBit(program, 2);
  boolean P2 = checkBit(program, 1);
  boolean B = checkBit(program, 0);

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
  if (!P1)
  {
    TurnOff(Pump1);
  }
}

void run()
{
  controlTemperature();
  SetPowerState();
  SetProgramState();

  SetOutputs(Program);
  delayer(0, 1);
}
