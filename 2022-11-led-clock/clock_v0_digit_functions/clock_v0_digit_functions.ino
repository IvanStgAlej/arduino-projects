#include <Adafruit_NeoPixel.h>

int PIN = 3;
int NumPixels=16;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NumPixels, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.show();

}

void loop() {  
apagar(pixels.Color(0, 0, 0), 0);
cero();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
uno();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
dos();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
tres();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
cuatro();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
cinco();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
seis();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
siete();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
ocho();
delay(1000);
apagar(pixels.Color(0, 0, 0), 0);
nueve();
delay(1000);
          
}
void apagar(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}

void cero(){
  pixels.setPixelColor(2,255,0,0);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.setPixelColor(12,255,0,0);
  pixels.setPixelColor(13,255,0,0);
  pixels.show();  
}

void uno(){  
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.show();
}

void dos(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.setPixelColor(12,255,0,0);
  pixels.setPixelColor(13,255,0,0);
  pixels.show();
}

void tres(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.show();
}

void cuatro(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(2,255,0,0);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.show();
}

void cinco(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(2,255,0,0);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.show();
}

void seis(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(2,255,0,0);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.setPixelColor(12,255,0,0);
  pixels.setPixelColor(13,255,0,0);
  pixels.show();
}

void siete(){  
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.show();
}
void ocho(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(2,255,0,0);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.setPixelColor(12,255,0,0);
  pixels.setPixelColor(13,255,0,0);
  pixels.show();
}

void nueve(){
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,255,0,0);
  pixels.setPixelColor(2,255,0,0);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(4,255,0,0);
  pixels.setPixelColor(5,255,0,0);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,255,0,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,255,0,0);
  pixels.setPixelColor(10,255,0,0);
  pixels.setPixelColor(11,255,0,0);
  pixels.show();
}
