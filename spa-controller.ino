int Heater = 13;
int Pump1 = 2;
int Pump1High = 3;
int Pump2 = 4;
int Blower = 5;
int Oxidizer = 6;
int Circulation = 7;

int stateAddress = 0;

int state = 0;
int readDelayCounter = 0;
boolean outputState[7] = {0, 0, 0, 0, 0, 0, 0};

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

void setup()
{
    Serial.begin(9600);
    pinMode(Heater, OUTPUT);
    for (int i = 1; i <= 7; i++)
    {
        pinMode(i, OUTPUT);
        TurnOff(i);
    }
    for (int i = 8; i <= 12; i++)
    {
        pinMode(i, INPUT_PULLUP);
    }
    Serial.println("Welcome to Caldera Utopia - modified");
    Serial.println("Type help for a list of commands");
}

void loop()
{
    while (Serial.available() > 0)
    {
        String input = Serial.readString();
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
            state = 0;
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
        run();
        break;
    case 5:
        Serial.println("Running circulation and Oxidizer");
        TurnOn(Circulation);
        TurnOn(Oxidizer);
        delayer(0, 30);
        TurnOff(Circulation);
        TurnOff(Oxidizer);
        break;
    default:
        Serial.println("Awaiting input. Type 'help' for commands - running main program in " + String(60 - readDelayCounter) + " seconds");
        delay(1000);
        readDelayCounter += 1;
        if (readDelayCounter > 60)
        {
            Serial.println("No input given. Running main program");
            state = 4;
        }
        break;
    }
}
