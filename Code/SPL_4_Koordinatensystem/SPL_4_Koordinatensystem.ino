#include <FastLED.h>
#include <JS.h>


// Define the number of LEDs in the strip
#define NUM_LEDS 256
// Define the data pin to which the strip is connected
#define DATA_PIN1 33
#define DATA_PIN2 23
// Define the dimensions of the LED panel
#define PANEL_WIDTH 64
#define PANEL_HEIGHT 16

// Create a CRGB array to store the colors of each LED
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
JS joystick(25,26,27);

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN1, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812, DATA_PIN2, GRB>(leds2, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  int x = 22; 
  int y = 12;  
  setPixel(x, y, CRGB::White);

  // Add a delay to slow down the animation
  delay(1000);
  // Clear the LED at the specified coordinates
  FastLED.clear();
  FastLED.show();
  // Add a delay before the next iteration
  delay(1000);
}

// Function to set the color of a specific LED at coordinates (x, y)
void setPixel(int x, int y, CRGB color) {
  // Check if the y-coordinate is even or odd to implement zigzag pattern
  int index;
    //first Panel
    if(y<8){
      x=31-x;
      if (x % 2 == 0) {
        // Even row
        index = x * PANEL_HEIGHT/2 + y;
      } else {
        // Odd row, reverse direction
        index = (x + 1) * PANEL_HEIGHT/2 - y - 1;
      }
      leds1[index] = color;
    }else {
      y = y - 8;
      y = 7 - y;
      if (x % 2 == 0) {
        // Even row
        index = x * PANEL_HEIGHT/2 + y;
      } else {
        // Odd row, reverse direction
        index = (x + 1) * PANEL_HEIGHT/2 - y - 1;
      }
      leds2[index] = color;
    }
  FastLED.show();
}

// Function to clear the color of a specific LED at coordinates (x, y)
void clearPixel(int x, int y) {
  setPixel(x, y, CRGB::Black);
}
