    #include <Adafruit_NeoPixel.h>
     
    #define PIN0 0
    #define PIN1 1
    #define PIN2 2
     
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN0, NEO_GRB + NEO_KHZ800);
    Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, PIN1, NEO_GRB + NEO_KHZ800);
    Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, PIN2, NEO_GRB + NEO_KHZ800);
     
    void setup() {
      strip.begin();
      strip.show();
      strip1.begin();
      strip1.show();
      strip2.begin();
      strip2.show();// Initialize all pixels to 'off'
    }
     
    void loop() {
      // all pixels show the same color:
      //(colour), wait
      colorWipe(strip.Color(0, 0, 50), 50); // blue
      colorWipe1(strip1.Color(0, 50, 0), 50); // green
      colorWipe2(strip2.Color(50, 0, 0), 50); // red
    }
     
    // Fill the dots one after the other with a color
    void colorWipe(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, c);
          strip.show();
          delay(wait);
      }
     
    }


     // Fill the dots one after the other with a color
    void colorWipe1(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip1.setPixelColor(i, c);
          strip1.show();
          delay(wait);
      }
    }

      // Fill the dots one after the other with a color
    void colorWipe2(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip2.setPixelColor(i, c);
          strip2.show();
          delay(wait);
      }
    }
