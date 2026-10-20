#include <Adafruit_NeoPixel.h>

int PIN=3; //Pin donde está conectada la tira de leds
int NUMPIXELS=8; //Número de leds conectados

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int espera = 50;
int estado = 0;
int color = 0;

int boton1 = 4;
int boton2 = 7;
int r = 5;
int g = 6;
int b = 8;


void setup() {
  // put your setup code here, to run once:
      pixels.begin(); // Inicialización
      pixels.show(); // Inicialitza tots els pixels apagats

      pinMode(boton1, INPUT);
      pinMode(boton2, INPUT);
      pinMode(r, OUTPUT);
      pinMode(g, OUTPUT);
      pinMode(b, OUTPUT);

      digitalWrite(r, 0);
      digitalWrite(g, 255);
      digitalWrite(b, 0);
      delay(500);
      digitalWrite(r, 0);
      digitalWrite(g, 0);
      digitalWrite(b, 0);
}

void on(uint32_t c, uint8_t wait) {
  for(int i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}
void off(uint32_t c, uint8_t wait) {
  for(int i=pixels.numPixels(); i>0-1; i--) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*50; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if (digitalRead(boton1) == LOW and estado == 0){
    if (color == 0){
     on(pixels.Color(0, 255, 0), espera);      
    }
    if (color == 1){
     on(pixels.Color(0, 0, 255), espera);      
    }
    if (color == 2){
     on(pixels.Color(255, 0, 0), espera);      
    }
    if (color == 3){
     on(pixels.Color(255, 255, 255), espera); 
    }
    if (color == 4){
      rainbowCycle(10);
    }


  estado = 1;
  delay(500);
  }
if (digitalRead(boton1) == LOW and estado == 1){
  off(pixels.Color(0, 0, 0), espera);
  
  estado = 0;
  delay(500);
}
if (digitalRead(boton2) == LOW){
  if (color == 4){
    color = 0;
  }
  else{
    color++;
  }
 if (color == 0){
  digitalWrite(r, 0);
  digitalWrite(g, 255);
  digitalWrite(b, 0);
  delay(500);
 }
 if (color == 1){
  digitalWrite(r, 0);
  digitalWrite(g, 0);
  digitalWrite(b, 255);
  delay(500);
 }
 if (color == 2){
  digitalWrite(r, 255);
  digitalWrite(g, 0);
  digitalWrite(b, 0);
  delay(500);
 }
 if (color == 3){
  digitalWrite(r, 255);
  digitalWrite(g, 255);
  digitalWrite(b, 255);
  delay(500);
 }
 if (color == 4){
  digitalWrite(r, 255);
  digitalWrite(g, 0);
  digitalWrite(b, 0);
  delay(200);
  digitalWrite(r, 0);
  digitalWrite(g, 255);
  digitalWrite(b, 0);
  delay(200);
  digitalWrite(r, 0);
  digitalWrite(g, 0);
  digitalWrite(b, 255);
  delay(200);
 }
  digitalWrite(r, 0);
  digitalWrite(g, 0);
  digitalWrite(b, 0);
}
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
