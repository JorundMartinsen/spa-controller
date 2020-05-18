int Pump1 = 2;
int Pump1High = 3;
int Pump2 = 4;
int Blower = 5;
int Oxidizer = 6;
int Circulation = 7;
int Relay7 = 8;
int Relay8 = 9;

int minutes = 1;
int seconds = 60;

// Calculate delay in ms
void delayer(int minutes = 0, int seconds = 1)
{
  delay(seconds * 1000 + minutes * 60000);
}

void TurnOn(int Relay)
{
  digitalWrite(Relay, LOW);
}

void TurnOff(int Relay)
{
  digitalWrite(Relay, HIGH);
}

void setup()
{

  for (int i = 2; i <= 9; i++)
  {
    pinMode(i, OUTPUT);
    TurnOff(i);
  }
  TurnOn(Circulation);
}

void loop()
{
  TurnOn(Circulation);
  delayer(0, 30);
  TurnOn(Oxidizer);
  delayer(0, 30);
  TurnOn(Pump1);
  delayer(0, 10);
  TurnOn(Pump2);
  delayer(0, 30);
  TurnOn(Blower);
  delayer(5, 0);
  TurnOff(Pump2);
  delayer(0, 30);
  TurnOff(Pump1);
  delayer(1, 0);
  TurnOff(Blower);
  //  // Channel 2
  //  TurnOn(Relay2); //Turn on relay
  //  delay(delayTime);
  //  TurnOff(Relay2); //Turn on relay
  //
  //  // Channel 3
  //  TurnOn(Relay3); //Turn on relay
  //  delay(delayTime);
  //  TurnOff(Relay3); //Turn on relay
  //
  //  // Channel 4
  //  TurnOn(Relay4); //Turn on relay
  //  delay(delayTime);
  //  TurnOff(Relay4); //Turn on relay
}
