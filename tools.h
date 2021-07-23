#include "common.h"

#ifndef TOOLS_H
#define TOOLS_H

void delayer(byte minutes = 0, byte seconds = 1)
{
    delay(seconds * 1000 + minutes * 60000);
}

void TurnOn(byte Relay)
{
    outputState[Relay] = true;
    digitalWrite(Relay, LOW);
}

void TurnOff(byte Relay)
{
    outputState[Relay] = false;
    digitalWrite(Relay, HIGH);
}

void switchState(boolean current, boolean last, byte output)
{
  if (current != last && current)
  {
    if (outputState[output])
    {
      TurnOff(output);
    }
    else
    {
      TurnOn(output);
    }
  }
}

boolean checkBit(byte input, byte bitNumber)
{
  return (input >> bitNumber & 0x01) == 0x01;
}

boolean checkButtonState(boolean button, boolean buttonLast)
{
  boolean state = button && button != buttonLast;
  buttonLast = button;
  return state;
}

#endif
