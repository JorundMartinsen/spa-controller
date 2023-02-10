#include "addresses.h"

// ~25°C -> 22

int temperatureArray[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte temperatureArrayIdx = 0;
byte temperatureArrayLength = 20;

int getTempLimit()
{
  // 620 => ~42°C
  // 575 => ~39°C
  // 425 => ~25°C
  int temperature = 37;
  return 134 + 8.6 * temperature + 0.07 * temperature * temperature;
}

int getTemperature()
{
    int temperatureAvg = 0;

    return analogRead(A0);


    // temperatureArray[temperatureArrayIdx] = 

//    for (int i = 0; i < temperatureArrayLength - 1; i++)
//    {
//        temperatureAvg += temperatureArray[i];
//    }
//    int res = temperatureAvg / temperatureArrayLength;
//    
//    return res;
}

void controlTemperature()
{
  int temperature = getTemperature();
  Serial.println(temperature);
  Serial.println(getTempLimit());
    if (temperature < (getTempLimit() - 10))
    {
        TurnOn(Heater);
        Serial.print(" Heating");
    }
    else if (temperature > (getTempLimit() + 10))
    {
        TurnOff(Heater);
        Serial.print(" Not Heating");
    }
    Serial.println();
}
