#include "common.h"

void switchState(boolean current, boolean last, int output)
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

void delayer(int minutes = 0, int seconds = 1)
{
    delay(seconds * 1000 + minutes * 60000);
}

void TurnOn(int Relay)
{
    outputState[Relay] = true;
    digitalWrite(Relay, LOW);
}

void TurnOff(int Relay)
{
    outputState[Relay] = false;
    digitalWrite(Relay, HIGH);
}