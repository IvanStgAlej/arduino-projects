const int altavoz = 3;
const int boton1 = 4;
const int boton2 = 5;
const int boton3 = 6;
const int boton4 = 7;
const int boton5 = 8;

const int luz1 = 11;
const int luz2 = 12;
const int luz3 = 19;
const int MenosOctaba = 9;
const int MasOctaba = 10;
const int tonos[3][8] = {
    {138, 155, 185, 207, 233},
    {277, 311, 369, 415, 466},
    {554, 622, 739, 830, 932}  
};

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;

int timePulse = 0;
int timeDispulse = 0;

int Menoctabapuls = 0;
int Masoctabapuls = 0;
int octabanum = 4;
int octaba =  1;
int tono = 0;

bool pulsado = false;
void setup() {
 Serial.begin(9600);
 pinMode(boton1, INPUT);
 pinMode(boton2, INPUT);
 pinMode(boton3, INPUT);
 pinMode(boton4, INPUT);
 pinMode(boton5, INPUT);
 pinMode(altavoz, OUTPUT);
 pinMode(MenosOctaba, INPUT);
 pinMode(MasOctaba, INPUT);
 pinMode(luz1, OUTPUT);
 pinMode(luz2, OUTPUT);
 pinMode(luz3, OUTPUT);
}

void loop() {
  value1 = digitalRead(boton1);
  value2 = digitalRead(boton2);
  value3 = digitalRead(boton3);
  value4 = digitalRead(boton4);
  value5 = digitalRead(boton5);

  Menoctabapuls = digitalRead(MenosOctaba);
  Masoctabapuls = digitalRead(MasOctaba);

  // Bajar de octaba
  if (Menoctabapuls  == LOW) {
    Serial.print("Bajar de octaba LOW / ");
    if (pulsado == false){
      octabanum = octabanum -1;
      if (octaba > 0) {
        octaba = octaba -1;
      }
      
      timePulse = millis();
      timeDispulse = 0;
    }
    pulsado = true;
  }

  if (Menoctabapuls == HIGH) {
      Serial.print("Bajar de octaba HIGH / ");
      
      timeDispulse = millis();
      if ((timeDispulse - timePulse) > 250){
        pulsado = false;
      }
    }


  // Subir de octaba
  if (Masoctabapuls  == LOW) {
    Serial.print("Subir de octaba LOW / ");
    if (pulsado == false){
      octabanum = octabanum +1;
      if (octaba < 2) {
        octaba = octaba +1;
      }
      
      timePulse = millis();
      timeDispulse = 0;
    }
    pulsado = true;
  }

  if (Masoctabapuls == HIGH) {
      Serial.print("Subir de octaba HIGH / ");
      timeDispulse = millis();
      if ((timeDispulse - timePulse) > 250){
        pulsado = false;
      }
    }


  if (value1 == LOW) {
      tono = tonos[octaba][0];
      }
  else if (value2 == LOW) {
      tono = tonos[octaba][1];
      }
  else if (value3 == LOW) {
      tono = tonos[octaba][2];
      } 
  else if (value4 == LOW) {
      tono = tonos[octaba][3];
      }
  else if (value5 == LOW) {
      tono = tonos[octaba][4];
      }                                       
  else {
      noTone(altavoz); 
      tono = 0;
      }
  
  
  if (tono != 0){
    tone(altavoz, tono);   
  }

  if (octaba == 0){
    digitalWrite(luz1, HIGH);
  }
  else if (octaba == 1){
    digitalWrite(luz1, HIGH);
  }
  else {
    digitalWrite(luz3, HIGH);
  }

 Serial.print("Tono: ");
 Serial.print(tono);
 Serial.print(" / Octaba: ");
 Serial.println(octaba);   
}
