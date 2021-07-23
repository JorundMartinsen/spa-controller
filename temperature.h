#include "addresses.h"

byte temperatureArray[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte temperatureArrayIdx = 0;
byte temperatureArrayLength = 20;

byte getTempLimit()
{
    return 512;
}

byte getTemperature()
{
    byte temperatureAvg = 0;

    temperatureArray[temperatureArrayIdx] = analogRead(A0);

    for (byte i = 0; i < temperatureArrayLength - 1; i++)
    {
        temperatureAvg += temperatureArray[i];
    }
    return temperatureAvg / temperatureArrayLength;
}

void controlTemperature()
{
    if (getTemperature() < getTempLimit())
    {
        digitalWrite(Heater, LOW);
        Serial.println("Circulation detected");
    }
    else
        digitalWrite(Heater, HIGH);
}