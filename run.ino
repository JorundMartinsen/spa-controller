void run()
{
  TurnOn(Circulation);
  delayer(0, 30);
  TurnOn(Oxidizer);
  delayer(0, 20);
  TurnOn(Pump1);
  delayer(0, 20);
  TurnOn(Pump2);
  delayer(0, 20);
  TurnOn(Blower);
  delayer(0, 20);
  TurnOn(Pump1High);
  delayer(5, 0);
  TurnOff(Pump2);
  delayer(0, 20);
  TurnOff(Pump1);
  delayer(0, 20);
  TurnOff(Pump1High);
  delayer(1, 20);
  TurnOff(Blower);
}
