
const int MenosOctaba = 10;
const int MasOctaba = 8;
const int boton1 = 3;
const int boton2 = 2;
const int boton3 = 4;
const int boton4 = 5;
const int boton5 = 6;
const int boton6 = 7;
const int boton7 = 12;
const int boton8 = 11;
const int luz = 13;
const int altavoz = 9;
const int tonos[3][8] = {
    {130, 146, 164, 174, 196, 220, 246, 261},
    {261, 293, 329, 349, 392, 440, 493, 523},
    {523, 587, 659, 698, 783, 880, 987, 1046}  
};
//const int countTonos = 10;

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;
int value6 = 0;
int value7 = 0;
int value8 = 0;

int timePulse = 0;
int timeDispulse = 0;

int Menoctabapuls = 0;
int Masoctabapuls = 0;
int octabanum = 4;
int octaba =  1;
int tono = 0;

bool pulsado = false;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(boton1, INPUT);
 pinMode(boton2, INPUT);
 pinMode(boton3, INPUT);
 pinMode(boton4, INPUT);
 pinMode(boton5, INPUT);
 pinMode(boton6, INPUT);
 pinMode(boton7, INPUT);
 pinMode(luz, OUTPUT);
 pinMode(altavoz, OUTPUT);
 pinMode(MenosOctaba, INPUT);
 pinMode(MasOctaba, INPUT);
}

void loop() {
  
  value1 = digitalRead(boton1);
  value2 = digitalRead(boton2);
  value3 = digitalRead(boton3);
  value4 = digitalRead(boton4);
  value5 = digitalRead(boton5);
  value6 = digitalRead(boton6);
  value7 = digitalRead(boton7);
  value8 = digitalRead(boton8);

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

  //delay(1000);
  
  // Teclas piano
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
  else if (value6 == LOW) {
      tono = tonos[octaba][5];
      }
  else if (value7 == LOW) {
      tono = tonos[octaba][6];
      } 
  else if (value8 == LOW) {
      tono = tonos[octaba][7];
      }                                       
  else {
      digitalWrite(luz, LOW);
      noTone(altavoz); 
      tono = 0;
      }
      
 if (tono != 0){
  digitalWrite(luz, HIGH);
  tone(altavoz, tono);   
 }

 Serial.print("Tono: ");
 Serial.print(tono);
 Serial.print(" / Octaba: ");
 Serial.println(octaba);
      
}
