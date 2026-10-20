#include <Servo.h>

Servo servoMotor; // Crea un objeto servo
int buttonPin = 2; // Pin del botón
int buttonState = 0; // Variable para el estado actual del botón
int lastButtonState = 0; // Variable para el último estado del botón
bool servoState = true; // Variable booleana para el estado del servo
unsigned long lastDebounceTime = 0; // El último tiempo en que el pin del botón se cambió de estado
unsigned long debounceDelay = 50; // Tiempo de debounce

void setup() {
  servoMotor.attach(9); // Conecta el servo al pin 9
  pinMode(buttonPin, INPUT); // Configura el pin del botón como entrada
  servoMotor.write(110); // Inicializa el servo en la posición original
}

void loop() {
  int reading = digitalRead(buttonPin); // Lee el estado del botón

  // Si el estado del botón ha cambiado
  if (reading != lastButtonState) {
    // Resetea el tiempo de debounce
    lastDebounceTime = millis();
  }

  // Si el tiempo desde el último cambio de estado es mayor que el tiempo de debounce
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si el estado del botón ha cambiado
    if (reading != buttonState) {
      buttonState = reading;

      // Solo cambia el estado del servo si el botón está presionado
      if (buttonState == HIGH) {
        servoState = !servoState; // Invierte el estado del servo
        if (servoState) {
          servoMotor.write(110); // Mueve el servo a su posición original (110 grados)
        } else {
          servoMotor.write(0); // Mueve el servo a 0 grados
        }
      }
    }
  }

  // Guarda el estado actual del botón como el último estado
  lastButtonState = reading;
}
