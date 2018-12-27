#include <FastLED.h>

#define LED_PIN      1   // which pin your pixels are connected to
#define NUM_LEDS    6   // how many LEDs you have
#define BRIGHTNESS 200   // 0-255, higher number is brighter. 
#define SATURATION 255   // 0-255, 0 is pure white, 255 is fully saturated color
#define SPEED       10   // How fast the colors move.  Higher numbers = faster motion
#define STEPS        10   // How wide the bands of color are.  1 = more like a gradient, 10 = more like stripes


#define COLOR_ORDER GRB  // Try mixing up the letters (RGB, GBR, BRG, etc) for a whole new world of color combinations

CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette( PartyColors_p );
TBlendType    currentBlending;
int ledMode = 0;


//FastLED comes with several palettes pre-programmed.  I like purple a LOT, and so I added a custom purple palette.

const TProgmemPalette16 PurpleColors_p PROGMEM =
{
  CRGB::Purple,
  CRGB::Purple, 
  CRGB::MidnightBlue,
  CRGB::MidnightBlue,

  CRGB::Purple,
  CRGB::Purple,
  CRGB::BlueViolet,
  CRGB::BlueViolet,

  CRGB::DarkTurquoise,
  CRGB::DarkTurquoise,
  CRGB::DarkBlue,
  CRGB::DarkBlue,

  CRGB::Purple,
  CRGB::Purple,
  CRGB::BlueViolet,
  CRGB::BlueViolet
};




void setup() {
  delay( 2000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentBlending =LINEARBLEND;

}

void loop() {

  

  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  switch (ledMode) {

  case 0:
    currentPalette = HeatColors_p;    //Red & Yellow, Fire Colors
    break;
  case 1:
    currentPalette = ForestColors_p;    //Foresty greens and yellows
    break;
  case 2: 
    currentPalette = OceanColors_p;  //Oceans are pretty and filled with mermaids
    break;
  case 3: 
    currentPalette = PurpleColors_p;  //My custom palette from above
    break;
  case 4:
    currentPalette = RainbowColors_p;  //All the colors!
    break;
  case 5:
    currentPalette = RainbowStripeColors_p;   //Rainbow stripes
    break;      
  case 6:
    currentPalette = PartyColors_p; //All the colors except the greens, which make people look a bit washed out
    break;
  } 

  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(1000 / SPEED);  
}

void FillLEDsFromPaletteColors( uint8_t colorIndex) {
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += STEPS;              
  }
}
