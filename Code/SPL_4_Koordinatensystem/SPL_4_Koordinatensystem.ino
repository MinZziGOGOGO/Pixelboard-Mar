#include <FastLED.h>

// Define the number of LEDs in the strip
#define NUM_LEDS 256
// Define the data pin to which the strip is connected
#define DATA_PIN1 5
#define DATA_PIN2 23
// Define the dimensions of the LED panel
#define PANEL_WIDTH 64
#define PANEL_HEIGHT 16

// Create a CRGB array to store the colors of each LED
CRGB leds[NUM_LEDS];

void setup() {
  // Initialize the FastLED library
  FastLED.addLeds<WS2812, DATA_PIN1, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, DATA_PIN2, GRB>(leds, NUM_LEDS);
  // Set brightness (0-255)
  FastLED.setBrightness(50);

  // Optional: Uncomment the following line to test all LEDs at startup
  // testLEDs();
}

void loop() {
  // Call your animation function here
  // In this example, we'll light up a single LED at coordinates (x, y)
  int x = 2; // X-coordinate
  int y = 5;  // Y-coordinate
  setPixel(x, y, CRGB::Red);

  // Add a delay to slow down the animation
  delay(1000);
  // Clear the LED at the specified coordinates
  clearPixel(x, y);
  // Add a delay before the next iteration
  delay(1000);
}

// Function to set the color of a specific LED at coordinates (x, y)
void setPixel(int x, int y, CRGB color) {
  // Check if the y-coordinate is even or odd to implement zigzag pattern
  int index;
  if(y <= PANEL_HEIGHT/2){
    x=31-x;
    if (x % 2 == 0) {
      // Even row
      index = x * PANEL_HEIGHT/2 + y;
    } else {
      // Odd row, reverse direction
      index = (x + 1) * PANEL_HEIGHT/2 - y - 1;
    }
  }else {
    y=y-8;
    if (x % 2 == 0) {
      // Even row
      index = x * PANEL_HEIGHT/2 + y + 256;
    } else {
      // Odd row, reverse direction
      index = (x + 1) * PANEL_HEIGHT/2 - y - 1 + 256;
    }
  }
  leds[index] = color;
  FastLED.show();
}

// Function to clear the color of a specific LED at coordinates (x, y)
void clearPixel(int x, int y) {
  setPixel(x, y, CRGB::Black);
}
