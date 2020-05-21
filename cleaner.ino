void cleaner()
{
    TurnOn(Circulation);
    TurnOn(Pump1);
    delayer(0, 2);
    TurnOff(Pump1);
    TurnOn(Pump2);
    delayer(0, 2);
    TurnOff(Pump2);
    TurnOn(Pump1);
    TurnOn(Pump1High);
    delayer(0, 2);
    TurnOff(Pump1High);
    TurnOff(Pump1);
    TurnOn(Blower);
    delayer(0, 2);
    TurnOff(Blower);
}