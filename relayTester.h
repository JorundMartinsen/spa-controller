#include "tools.h"
#include "addresses.h"

void relayTester()
{
        TurnOn(Circulation);
        delay(1000);
        TurnOff(Circulation);
        delay(1000);

        TurnOn(Pump2);
        delay(1000);
        TurnOff(Pump2);
        delay(1000);

        TurnOn(Pump1);
        delay(1000);
        TurnOn(Pump1High);
        delay(1000);
        TurnOff(Pump1High);
        delay(1000);
        TurnOff(Pump1);
        delay(1000);

        TurnOn(Blower);
        delay(1000);
        TurnOff(Blower);
        delay(1000);
}
