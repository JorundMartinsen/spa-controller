#include "addresses.h"
#include "common.h"
#include "tools.h"
#include "cleaner.h"
#include "airRemoval.h"
#include "relayTester.h"
#include "run.ino"

int stateAddress = 0;

int state = 3;
int readDelayCounter = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(Heater, OUTPUT);
    pinMode(Circulation, OUTPUT);
    pinMode(Pump2, OUTPUT);
    pinMode(Pump1, OUTPUT);
    pinMode(Pump1High, OUTPUT);
    pinMode(Blower, OUTPUT);
    TurnOff(Circulation);
    TurnOff(Pump2);
    TurnOff(Pump1);
    TurnOff(Pump1High);
    TurnOff(Blower);
    
        pinMode(2, INPUT_PULLUP);
    
    Serial.println("Welcome to Caldera Utopia - modified");
    Serial.println("Type help for a list of commands");
}

void loop()
{
    while (Serial.available() > 0)
    {
        String input = Serial.readString();
        Serial.println("I read: ");
        Serial.println(input);
        if (input == "clean")
        {
            state = 1;
        }
        else if (input == "air")
        {
            state = 2;
        }
        else if (input == "test")
        {
            state = 3;
        }
        else if (input == "run")
        {
            state = 4;
        }
        else if (input == "circulation")
        {
            state = 5;
        }
        else
        {
            state = 3;
            Serial.println("These are the available commands:");
            Serial.println("clean\truns the cleaning program");
            Serial.println("air\tclears the circulation pump for air");
            Serial.println("test\truns a test on all relay outputs");
            Serial.println("circulation\truns the circulation program");
            Serial.println("run\truns the main program");
        }
    }
    switch (state)
    {
    case 1:
        Serial.println("Running cleaning program");
        TurnOn(Circulation);
        cleaner();
        break;
    case 2:
        Serial.println("Running air removal program");
        airRemoval();
        break;
    case 3:
        Serial.println("Running relay tests");
        relayTester();
        break;
    case 4:
        TurnOn(Circulation);
        // run();
        break;
    case 5:
        Serial.println("Running circulation");
        TurnOn(Circulation);
        delayer(0, 30);
        TurnOff(Circulation);
        break;
    default:
        Serial.println("Awaiting input. Type 'help' for commands - running circulation program in " + String(60 - readDelayCounter) + " seconds");
        delay(1000);
        readDelayCounter += 1;
        if (readDelayCounter > 60)
        {
            Serial.println("No input given. Running circulation program");
            state = 4;
        }
        break;
    }
}
