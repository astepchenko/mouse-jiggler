#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Mouse.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// #define COUNTER_COL 60 // Counter horisontal position, default display
// #define TEXT_COL 40 // Text horisontal position, default display
// #define TEXT_ROW 15 // Text vertical position, default display
#define COUNTER_COL 55 // Counter horisontal position, flipped display
#define TEXT_COL 35 // Text horisontal position, flipped display
#define TEXT_ROW 5 // Text vertical position, flipped display

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  delay(2000); // Wait for initializing
  display.clearDisplay(); // Clear display

  display.setRotation(2); // Flip display

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(TEXT_COL, TEXT_ROW);
  display.println("CLICK");
  display.display();

  Mouse.begin();
}

uint8_t textShift(uint8_t num) {
  if (num > 99) return 10;
  else if (num > 9) return 5;
  else return 0;
}

void loop() {

  while(true) {
    Mouse.move(4,0,0);
    delay(100);
    Mouse.move(-4,0,0);

    delay(1000);

    for (int i = 120; i >= 0; i--) {
      display.clearDisplay();
      display.setCursor(COUNTER_COL - textShift(i), TEXT_ROW);
      display.println(i);
      display.fillRect(7, 28, i, 4, WHITE);
      display.display();

      delay(1000);
    }

    display.clearDisplay();
    display.setCursor(TEXT_COL, TEXT_ROW);
    display.println("CLICK");
    display.display();
  }
}
