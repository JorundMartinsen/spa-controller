#include "addresses.h"

// ~25°C -> 22


int temperatureArray[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte temperatureArrayIdx = 0;
byte temperatureArrayLength = 20;

int getTempLimit()
{
    return 512;
}

int getTemperature()
{
    int temperatureAvg = 0;

    temperatureArray[temperatureArrayIdx] = analogRead(A0);

    for (int i = 0; i < temperatureArrayLength - 1; i++)
    {
        temperatureAvg += temperatureArray[i];
    }
    int res = temperatureAvg / temperatureArrayLength;
    Serial.println(res);
    return res;
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