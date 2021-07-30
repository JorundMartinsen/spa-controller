#include "tools.h"
#include "addresses.h"

int manual(String input, int state)
{
  if (input == "Circulation on"){
    TurnOn(Circulation); 
  }
  else if (input == "Circulation off"){
    TurnOff(Circulation); 
  }
  else if (input == "Pump1 on"){
    TurnOn(Pump1); 
  }
  else if (input == "Pump1 off"){
    TurnOff(Pump1); 
  }
  else if (input == "Pump1High on"){
    TurnOn(Pump1High); 
  }
  else if (input == "Pump1High off"){
    TurnOff(Pump1High); 
  }
  else if (input == "Pump2 on"){
    TurnOn(Pump2); 
  }
  else if (input == "Pump2 off"){
    TurnOff(Pump2); 
  }
  else if (input == "Blower on"){
    TurnOn(Blower); 
  }
  else if (input == "Blower off"){
    TurnOff(Blower); 
  }
  else if (input == "exit"){
    return 0;
  }
  return state;
}
