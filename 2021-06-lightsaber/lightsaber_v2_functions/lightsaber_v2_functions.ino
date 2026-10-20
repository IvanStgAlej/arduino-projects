#include <Adafruit_NeoPixel.h>

int PIN=3; //Pin donde está conectada la tira de leds
int NUMPIXELS=40; //Número de leds conectados

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int espera = 50;
int estado = 0;

int boton = 4;

void setup() {
  // put your setup code here, to run once:
      pixels.begin(); // Inicialización
      pixels.show(); // Inicialitza tots els pixels apagats

      pinMode(boton, INPUT);

}

void colorWipeON(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}
void colorWipeOFF(int c, int wait) {
  for(int i=pixels.numPixels(); i>=0; i--) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(boton) == LOW and estado == 0){
    colorWipeON(pixels.Color(0, 255, 0), 50);
    estado = 1;
    delay(759);
    }

if (digitalRead(boton) == LOW and estado == 1){
  colorWipeOFF(pixels.Color(0, 0, 0), 50);
  estado = 0;
  delay(759);
  }
}
