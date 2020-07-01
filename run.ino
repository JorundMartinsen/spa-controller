  boolean lastP1Button = false;
  boolean lastP1HButton = false;
  boolean lastP2Button = false;
  boolean lastBlowerButton = false;

void switchState(boolean current, boolean last, int output){
  if (current != last && current){
      if(outputState[output]) {
        TurnOff(output);
      }
      else {
        TurnOn(output);
      }
  }
}

void run()
{
  boolean P1Button = digitalRead(9);
  boolean P1HButton = digitalRead(10);
  boolean P2Button = digitalRead(11);
  boolean BlowerButton = digitalRead(12);
  TurnOn(Circulation);
  TurnOn(Oxidizer);
  switchState(P1Button, lastP1Button, Pump1);
  switchState(P1HButton, lastP1HButton, Pump1High);
  switchState(P2Button, lastP2Button, Pump2);
  switchState(BlowerButton, lastBlowerButton, Blower);

  lastP1Button = P1Button;
  lastP1HButton = P1HButton;
  lastP2Button = P2Button;
  lastBlowerButton = BlowerButton;
}
