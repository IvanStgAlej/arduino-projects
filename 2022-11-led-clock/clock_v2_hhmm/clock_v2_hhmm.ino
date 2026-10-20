#include <Adafruit_NeoPixel.h>
#include <virtuabotixRTC.h>

int CentenaMin, DecenaMin, UnidadMin, ValorMin;
int UnidadAnteriorMin = 10;
int DecenaAnteriorMin = 10;

int CentenaHora, DecenaHora, UnidadHora, ValorHora;
int UnidadAnteriorHora = 10;
int DecenaAnteriorHora = 10;

uint16_t NumDig;
int Etapa = 0;
int color[] = {0, 50, 50};
int apagado[] = {0, 0, 0};

// Definir pines
const int ledPin = 5;  // Pin conectado al LED
const int buttonPin = 4; // Pin conectado al boton

// Variables de estado
bool ledState = true; // Estado actual del LED (apagado al inicio)
bool buttonState = false; // Estado del boton
bool lastButtonState = false; // Estado anterior del boton

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

int reloj_off[] = {2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool relojActivo = true;
bool lastRelojActivo = relojActivo;

int PIN = 3;
int NumPixels=56;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NumPixels, PIN, NEO_GRB + NEO_KHZ800);
virtuabotixRTC myRTC(6, 7, 8);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();

  pinMode(ledPin, OUTPUT); // Configurar el pin del LED como salida
  pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del boton como entrada con resistencia pull-up
  digitalWrite(ledPin, ledState); //Actualiza el led para que empiece encendido

  // Forzar actualizacion inicial de todos los digitos
  recargarReloj();
}

void loop() {
  buttonState = digitalRead(buttonPin); // Leer el estado del boton

  // Detectar cambio de estado del boton
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState; // Cambiar el estado del LED
    relojActivo = !relojActivo; // Apagar el reloj
    digitalWrite(ledPin, ledState); // Actualizar el LED
    delay(100); // Pequeno retraso para evitar rebotes
  }

  lastButtonState = buttonState;

  if (relojActivo) {
    if (relojActivo != lastRelojActivo){
      recargarReloj();
      lastRelojActivo = relojActivo; // Actualizar el estado del reloj
    }
    
    actualizarReloj();
  }
  else {
    // Comprobar que es la primera vez que se apaga
    if (relojActivo != lastRelojActivo){
      pintar(reloj_off, color, 1);
      pintar(reloj_off, color, 2);
      pintar(reloj_off, color, 3);
      pintar(reloj_off, color, 4);

      lastRelojActivo = relojActivo; // Actualizar el estado del reloj
    }
  }
}

void recargarReloj(){
  // Forzar actualizacion inicial de todos los digitos
  myRTC.updateTime();
  ValorMin = myRTC.minutes;
  ValorHora = myRTC.hours;

  DecenaMin = ValorMin / 10;
  UnidadMin = ValorMin % 10;
  DecenaHora = ValorHora / 10;
  UnidadHora = ValorHora % 10;

  pintar(digitos[DecenaHora], color, 4);
  pintar(digitos[UnidadHora], color, 3);
  pintar(digitos[DecenaMin], color, 2);
  pintar(digitos[UnidadMin], color, 1);
}

void actualizarReloj() {
  size_t n;
  UnidadAnteriorMin = UnidadMin;
  DecenaAnteriorMin = DecenaMin;
  UnidadAnteriorHora = UnidadHora;
  DecenaAnteriorHora = DecenaHora;
  
  myRTC.updateTime();

  // Actualizar minutos
  ValorMin = myRTC.minutes;

  DecenaMin = ValorMin / 10;
  UnidadMin = ValorMin % 10;

  if (UnidadAnteriorMin != UnidadMin) {
    NumDig = 1;
    pintar(digitos[UnidadMin], color, NumDig);
  }

  if (DecenaAnteriorMin != DecenaMin) {
    NumDig = 2;
    pintar(digitos[DecenaMin], color, NumDig);
  }

  // Actualizar horas
  ValorHora = myRTC.hours;

  DecenaHora = ValorHora / 10;
  UnidadHora = ValorHora % 10;

  if (UnidadAnteriorHora != UnidadHora) {
    NumDig = 3; // Tercer digito para las horas (unidades)
    pintar(digitos[UnidadHora], color, NumDig);
  }

  if (DecenaAnteriorHora != DecenaHora) {
    NumDig = 4; // Cuarto digito para las horas (decenas)
    pintar(digitos[DecenaHora], color, NumDig);
  }
}

void pintar(uint16_t* pixelesAEncender, int color[], uint16_t Dig) {
  borrar(digitos[8], apagado, Dig);
  int n = pixelesAEncender[0];
  for (int i = 1; i < n + 1; i++) {
    int PA = pixelesAEncender[i] + ((Dig - 1) * 14);
    pixels.setPixelColor(PA, pixels.Color(color[0], color[1], color[2]));
    pixels.show();
  }
}

void borrar(uint16_t pixelesAEncender[], uint16_t color[], uint16_t Dig) {
  int n = pixelesAEncender[0];
  for (int i = 1; i < n + 1; i++) {
    int PA = pixelesAEncender[i] + ((Dig - 1) * 14);
    pixels.setPixelColor(PA, pixels.Color(color[0], color[1], color[2]));
    pixels.show();
  }
}
