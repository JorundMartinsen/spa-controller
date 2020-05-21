void airRemoval()
{
  TurnOn(Circulation);
  delayer(0, 5);
  TurnOff(Circulation);
  delayer(0, 10);
}
