#include <Mouse.h>

// This is runned once, during device initialization
void setup()
{
  Mouse.begin();
}

// Main loop - move mouse back and forth every 120 seconds
void loop()
{
  delay(1000);

  while(true) {
    Mouse.move(4,0,0);
    delay(100);
    Mouse.move(-4,0,0);
    delay(120000);
  }
}
