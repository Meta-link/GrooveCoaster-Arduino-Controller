#include <SwitchControlLibrary.h>

// Button Pins
const int Pin_ButtonA = 4;
const int Pin_ButtonB = 6;
const int Pin_ButtonX = 5;
const int Pin_ButtonY = 7;

const int Pin_ButtonL = 8;
const int Pin_ButtonR = 3;

const int Pin_ButtonStart = 2;

const int Pin_DpadUp    = 9;
const int Pin_DpadDown  = 10;
const int Pin_DpadLeft  = 12;
const int Pin_DpadRight = 11;

bool previousStateA = false;
unsigned long timeA;
bool previousStateB = false;
unsigned long timeB;
bool previousStateX = false;
unsigned long timeX;
bool previousStateY = false;
unsigned long timeY;

bool previousStateL = false;
unsigned long timeL;
bool previousStateR = false;
unsigned long timeR;

bool previousStateStart = false;
unsigned long timeStart;

Hat previousDPad = Hat::CENTER;
unsigned long timeDPad;

unsigned long timer = 5;

void setup() {
  pinMode(Pin_ButtonA, INPUT);
  pinMode(Pin_ButtonB, INPUT);
  pinMode(Pin_ButtonX, INPUT);
  pinMode(Pin_ButtonY, INPUT);

  pinMode(Pin_ButtonL, INPUT);
  pinMode(Pin_ButtonR, INPUT);

  pinMode(Pin_ButtonStart, INPUT);

  pinMode(Pin_DpadUp, INPUT);
  pinMode(Pin_DpadDown, INPUT);
  pinMode(Pin_DpadLeft, INPUT);
  pinMode(Pin_DpadRight, INPUT);

  SwitchControlLibrary().PressButtonPlus();
  SwitchControlLibrary().ReleaseButtonPlus();
}

void loop() {
  unsigned long currentMillis = millis();
  
  boolean buttonA = !digitalRead(Pin_ButtonA);
  boolean buttonB = !digitalRead(Pin_ButtonB);
  boolean buttonX = !digitalRead(Pin_ButtonX);
  boolean buttonY = !digitalRead(Pin_ButtonY);

  boolean buttonL = !digitalRead(Pin_ButtonL);
  boolean buttonR = !digitalRead(Pin_ButtonR);

  boolean buttonStart = !digitalRead(Pin_ButtonStart);

  boolean dpadUp    = !digitalRead(Pin_DpadUp);
  boolean dpadDown  = !digitalRead(Pin_DpadDown);
  boolean dpadLeft  = !digitalRead(Pin_DpadLeft);
  boolean dpadRight = !digitalRead(Pin_DpadRight);

  if(buttonA != previousStateA && currentMillis - timeA > timer)
  {
    if(buttonA)
      SwitchControlLibrary().PressButtonA();
    else
      SwitchControlLibrary().ReleaseButtonA();
    previousStateA = buttonA;
    timeA = currentMillis;
  }

  if(buttonB != previousStateB && currentMillis - timeB > timer)
  {
    if(buttonB)
      SwitchControlLibrary().PressButtonB();
    else
      SwitchControlLibrary().ReleaseButtonB();
    previousStateB = buttonB;
    timeB = currentMillis;
  }

  if(buttonX != previousStateX && currentMillis - timeX > timer)
  {
    if(buttonX)
      SwitchControlLibrary().PressButtonX();
    else
      SwitchControlLibrary().ReleaseButtonX();
    previousStateX = buttonX;
    timeX = currentMillis;
  }

  if(buttonY != previousStateY && currentMillis - timeY > timer)
  {
    if(buttonY)
      SwitchControlLibrary().PressButtonY();
    else
      SwitchControlLibrary().ReleaseButtonY();
    previousStateY = buttonY;
    timeY = currentMillis;
  }

  if(buttonL != previousStateL && currentMillis - timeL > timer)
  {
    if(buttonL)
    {
      SwitchControlLibrary().PressButtonL();
    }
    else
    {
      SwitchControlLibrary().ReleaseButtonL();
    }
    previousStateL = buttonL;
    timeL = currentMillis;
  }

  if(buttonR != previousStateR && currentMillis - timeR > timer)
  {
    if(buttonR)
      SwitchControlLibrary().PressButtonR();
    else
      SwitchControlLibrary().ReleaseButtonR();
    previousStateR = buttonR;
    timeR = currentMillis;
  }
  
  if(buttonStart != previousStateStart && currentMillis - timeStart > timer)
  {
    if(buttonStart)
      SwitchControlLibrary().PressButtonPlus();
    else
      SwitchControlLibrary().ReleaseButtonPlus();
    previousStateStart = buttonStart;
    timeStart = currentMillis;
  }
  
  Hat dPad = Hat::CENTER;
  if(dpadUp || dpadDown || dpadLeft || dpadRight)
  {
    if(dpadUp)
    {
      if(dpadLeft)
      {
        dPad = Hat::TOP_LEFT;
      }
      else if(dpadRight)
      {
        dPad = Hat::TOP_RIGHT;
      }
      else
      {
        dPad = Hat::TOP;
      }
    }
    else if(dpadDown)
    {
      if(dpadLeft)
      {
        dPad = Hat::BOTTOM_LEFT;
      }
      else if(dpadRight)
      {
        dPad = Hat::BOTTOM_RIGHT;
      }
      else
      {
        dPad = Hat::BOTTOM;
      }
    }
    else if(dpadRight)
    {
      dPad = Hat::RIGHT;
    }
    else if(dpadLeft)
    {
      dPad = Hat::LEFT;
    }
  }
    
  if(dPad != previousDPad && currentMillis - timeStart > timer)
  {
    SwitchControlLibrary().MoveHat((uint8_t) dPad);
    previousDPad = dPad;
    timeDPad = currentMillis;
  }
  
}
