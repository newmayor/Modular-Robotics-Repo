#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper1 (1,6,3); // Defaults to 4 pins on 2, 3, 4, 5
AccelStepper stepper2 (1,4,5); // Defaults to 4 pins on 2, 3, 4, 5

int pos1 = 10000;
int pos2 = 10000;

void setup()
{  
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(800);
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(800);
}

void loop()
{
  if (stepper1.distanceToGo() == 0)
  {
        pos1 = -pos1;
    stepper1.moveTo(pos1);
  }
  if (stepper2.distanceToGo() == 0)
  {
     
    stepper2.moveTo(pos2);
    pos2 = -pos2;
  }
  stepper1.run();
  stepper2.run();
}
