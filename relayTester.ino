void relayTester()
{
    for (int i = 2; i <= 9; i++)
    {
        TurnOn(i);
        delay(500);
        TurnOff(i);
    }
}