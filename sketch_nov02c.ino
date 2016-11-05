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
    Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(7, PIN0, NEO_GRB + NEO_KHZ800);
    Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, PIN1, NEO_GRB + NEO_KHZ800);
    Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(3, PIN2, NEO_GRB + NEO_KHZ800);
     
    void setup() {
      strip0.begin();
      strip0.show();
      strip1.begin();
      strip1.show();
      strip2.begin();
      strip2.show();// Initialize all pixels to 'off'
    }
     
    void loop() {
      // all pixels show the same color:
      //(colour), wait

      strip0.setBrightness(10);
      strip1.setBrightness(30);
      strip2.setBrightness(30);

      
      colorWipe(strip0.Color(0, 0, 50), 50); // blue
      colorWipe1(strip1.Color(0, 50, 0), 50); // green
      colorWipe2(strip2.Color(50, 0, 0), 50); // red
    }
     
    // Fill the dots one after the other with a color
    void colorWipe(uint32_t cb, uint8_t wait) {
      uint32_t r =strip0.Color(50, 0, 0);
      uint32_t g =strip0.Color(0, 50, 0);
      uint32_t b =strip0.Color(0, 0, 50);
      
      //You can have fun here changing the colors for the code
      uint32_t color1 = strip0.Color(236, 79, 100); //Salmon Pink
      uint32_t color2 = strip0.Color(246, 216, 180); //Cream
      uint32_t color3 = strip0.Color(174, 113, 208); //Lavendar
      uint32_t color4 = strip0.Color(182, 31, 40); //Red
      uint32_t color5 = strip0.Color(91, 44, 86); //Purple
   
      //strip0.setPixelColor(0,r);
      //strip0.setPixelColor(1,g);
      //strip0.setPixelColor(2,b);
      //strip0.setPixelColor(3,r);      
      //strip0.setPixelColor(4,g);
      //strip0.setPixelColor(5,b);
      //strip0.setPixelColor(6,r);
      //strip0.show();

        strip0.setPixelColor(1, color1); 
        strip0.setPixelColor(2, color1); 
        strip0.setPixelColor(3, color1); 
        strip0.setPixelColor(4, color1); 
        strip0.setPixelColor(5, color1); 
        strip0.setPixelColor(6, color1); 
        strip0.setPixelColor(0, color2); 
        
        strip0.show();
        delay(3000);
        
        
        strip0.setPixelColor(1, color2); 
        strip0.setPixelColor(2, color2); 
        strip0.setPixelColor(3, color2); 
        strip0.setPixelColor(4, color2); 
        strip0.setPixelColor(5, color2); 
        strip0.setPixelColor(6, color2); 
        strip0.setPixelColor(0, color3); 
        
        strip0.show();
        delay(3000);
  
    }


     // Fill the dots one after the other with a color
    void colorWipe1(uint32_t c, uint8_t wait) {
    
          strip1.setPixelColor(0, c);
          strip1.show();
    
    }

      // Fill the dots one after the other with a color
    void colorWipe2(uint32_t c, uint8_t wait) {
          uint32_t r =strip2.Color(50, 0, 0);
          uint32_t g =strip2.Color(0, 50, 0);
          uint32_t b =strip2.Color(0, 0, 50);
          uint32_t none =strip2.Color(0, 0, 0);
          
          strip2.setPixelColor(0, r);
          strip2.setPixelColor(1, none);
          strip2.setPixelColor(2, none);
          
          strip2.show();
          delay(2000);
          
          strip2.setPixelColor(0, none);
          strip2.setPixelColor(1, g);
          strip2.setPixelColor(2, none);
          
          strip2.show();
          delay(2000);
          
          strip2.setPixelColor(0, none);
          strip2.setPixelColor(1, none);
          strip2.setPixelColor(2, b);
          
          strip2.show();
          delay(20);
    }
