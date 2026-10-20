
#include <Adafruit_NeoPixel.h>

int PIN=3; //Pin donde está conectada la tira de leds
int NUMPIXELS=8; //Número de leds conectados

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int espera = 50;
int estado = 0;

int boton = 4;

void setup() {
      pixels.begin(); // Inicialización
      pixels.show(); // Inicialitza tots els pixels apagats

      pinMode(boton, INPUT);
}

void loop() {
  if (digitalRead(boton) == LOW and estado == 0){
  pixels.setPixelColor(0,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(1,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(2,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(3,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(4,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(5,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(6,0,255,0);
  pixels.show();
  delay(espera);
  pixels.setPixelColor(7,0,255,0);
  pixels.show();
  delay(espera);

  estado = 1;
  delay(1000);
  }

  if (digitalRead(boton) == LOW and estado == 1){
    pixels.setPixelColor(7,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(6,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(5,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(4,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(3,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(2,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(1,0,0,0);
    pixels.show();
    delay(espera);
    pixels.setPixelColor(0,0,0,0);
    pixels.show();
    delay(espera);

    estado = 0;
    delay(1000);
  }


}
