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

    long prewStrip0 = 0;
    int ledState0 = LOW;    
    long interval0 = 1000;  

    long prewStrip1 = 0;
    int ledState1 = LOW;    
    long interval1 = 1000;  

    long prewStrip2 = 0;
    char ledState2 = 'R';    
    long interval2 = 1000;  
     
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

     
      
     // colorWipe(); 
      colorWipe1(); 
     // colorWipe2(); 
    }
     
    // Fill the dots one after the other with a color
    void colorWipe() {
      uint32_t r =strip0.Color(50, 0, 0);
      uint32_t g =strip0.Color(0, 50, 0);
      uint32_t b =strip0.Color(0, 0, 50);
      unsigned long currentStrip0 = millis();

      if(currentStrip0 - prewStrip0 > interval0) {
        // save the last time you blinked the LED 
        prewStrip0 = currentStrip0;   
     
        // if the LED is off turn it on and vice-versa:
        if (ledState0 == LOW){
          ledState0 = HIGH;
          strip0.setPixelColor(0,r);
          strip0.setPixelColor(1,r);
          strip0.setPixelColor(2,r);
          strip0.setPixelColor(3,r);      
          strip0.setPixelColor(4,r);
          strip0.setPixelColor(5,r);
          strip0.setPixelColor(6,r);
          strip0.show();
          }
        else{
          ledState0 = LOW;
          strip0.setPixelColor(1, r); 
          strip0.setPixelColor(2, r); 
          strip0.setPixelColor(3, r); 
          strip0.setPixelColor(4, r); 
          strip0.setPixelColor(5, r); 
          strip0.setPixelColor(6, r); 
          strip0.setPixelColor(0, b);  
          strip0.show();
          }
        }
    }


     // Fill the dots one after the other with a color
    void colorWipe1() {
         
          for (int i = 20; i < 150; i++){
            strip1.setPixelColor(0, strip1.Color(0,i,0));
            strip1.show();
            delay (40);
          }
          for (int i = 150; i > 20; i--){
            strip1.setPixelColor(0, strip1.Color(0,i,0));
            strip1.show();
            delay (40);
          }
          
     
           
            
       
    
    }

      // Fill the dots one after the other with a color
    void colorWipe2() {
      uint32_t r =strip2.Color(50, 0, 0);
      uint32_t g =strip2.Color(0, 50, 0);
      uint32_t b =strip2.Color(0, 0, 50);
      uint32_t none =strip2.Color(0, 0, 0);
      unsigned long currentStrip2 = millis();

      if(currentStrip2 - prewStrip2 > interval2) {
        // save the last time you blinked the LED 
        prewStrip2 = currentStrip2;   


        switch(ledState2) {
      case 'R' :
          strip2.setPixelColor(0, r);
          strip2.setPixelColor(1, none);
          strip2.setPixelColor(2, none);
          
          strip2.show();
          ledState2 = 'G';
         break;
      case 'G' :
          strip2.setPixelColor(0, none);
          strip2.setPixelColor(1, g);
          strip2.setPixelColor(2, none);
          
          strip2.show();
          ledState2 = 'B';
         break;
      case 'B' :
          strip2.setPixelColor(0, none);
          strip2.setPixelColor(1, none);
          strip2.setPixelColor(2, b);
          
          strip2.show();
          ledState2 = 'R';
         break;
      }
        
     }
 
  }
