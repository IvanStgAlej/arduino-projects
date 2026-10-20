#include <Adafruit_NeoPixel.h>
#include <virtuabotixRTC.h>

int Centena, Decena, Unidad, Valor;
int UnidadAnterior, DecenaAnterior;
uint16_t NumDig;
int Etapa = 0;
int color[] = {255, 0, 0};
int apagado[] = {0, 0, 0};


uint16_t digitos[10][15] {
  {12,2,3,4,5,6,7,8,9,10,11,12,13,0,0}
 ,{4,6,7,8,9,0,0,0,0,0,0,0,0,0,0}
 ,{10,0,1,4,5,6,7,10,11,12,13,0,0,0,0}
 ,{10,0,1,4,5,6,7,8,9,10,11,0,0,0,0}
 ,{8,0,1,2,3,6,7,8,9,0,0,0,0,0,0}
 ,{10,0,1,2,3,4,5,8,9,10,11,0,0,0,0}
 ,{12,0,1,2,3,4,5,8,9,10,11,12,13,0,0}
 ,{6,4,5,6,7,8,9,0,0,0,0,0,0,0,0}
 ,{14,0,1,2,3,4,5,6,7,8,9,10,11,12,13}
 ,{12,0,1,2,3,4,5,6,7,8,9,10,11,0,0,}
};

// uint16_t cero[]   = {2,3,4,5,6,7,8,9,10,11,12,13};
// uint16_t uno[]    = {6,7,8,9};
// uint16_t dos[]    = {0,1,4,5,6,7,10,11,12,13};
// uint16_t tres[]   = {0,1,4,5,6,7,8,9,10,11};
// uint16_t cuatro[] = {0,1,2,3,6,7,8,9};
// uint16_t cinco[]  = {0,1,2,3,4,5,8,9,10,11};
// uint16_t seis[]   = {0,1,2,3,4,5,8,9,10,11,12,13};
// uint16_t siete[]  = {4,5,6,7,8,9};
// uint16_t ocho[]   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
// uint16_t nueve[]  = {0,1,2,3,4,5,6,7,8,9,10,11};

int PIN = 3;
int NumPixels=28;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NumPixels, PIN, NEO_GRB + NEO_KHZ800);
virtuabotixRTC myRTC(6, 7, 8);

void setup() {

  Serial.begin(9600);
  pixels.begin();
  pixels.show();
  
}


void loop() {
  // put your main code here, to run repeatedly:
  // put your setup code here, to run once:
  size_t n;
  
  
  pintar(digitos[9], color, 2);
  delay(2000);
  pintar(digitos[8], color, 2);
  delay(2000);
  pintar(digitos[7], color, 2);
  delay(2000);
  pintar(digitos[6], color, 2);
  delay(2000);
  pintar(digitos[5], color, 2);
  delay(2000);
  pintar(digitos[4], color, 2);
  delay(2000);
  pintar(digitos[3], color, 2);
  delay(2000);
  pintar(digitos[2], color, 2);
  delay(2000);
  pintar(digitos[1], color, 2);
  delay(2000);
  pintar(digitos[0], color, 2);
  delay(2000);
}



void pintar(uint16_t* pixelesAEncender, int color[], uint16_t Dig){

  borrar(digitos[8], apagado, Dig);
  int n = pixelesAEncender[0];
  for(int i= 1; i < n+1; i++){
    Serial.print(i);
    Serial.print(pixelesAEncender[i]);
    Serial.print(" ");
    int PA = pixelesAEncender[i] + ((Dig - 1) * 14);
    Serial.print(PA);
    Serial.print(" ");
    pixels.setPixelColor(PA, pixels.Color(color[0], color[1], color[2]));
    pixels.show();
  }
  Serial.print(" --- ");
}

void borrar(uint16_t pixelesAEncender[], uint16_t color[], uint16_t Dig){
  size_t n = digitos[8][0];
  for(int i= 0; i < n; i++){
    int PA = pixelesAEncender[i] + ((Dig - 1) * 14);
    pixels.setPixelColor(PA, pixels.Color(color[0], color[1], color[2]));
    pixels.show();
  }
}
