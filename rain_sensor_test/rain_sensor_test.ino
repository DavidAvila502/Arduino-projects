#include <Servo.h>

Servo miServo;       // Objeto para controlar el servo [cite: 113]
int pinSensor = A0;  // Pin analógico para el sensor FC-37
int valorLluvia;
int umbral = 500;    // Ajusta este valor (menor valor = más agua)
int servoPosition = 0; 

void setup() {
  Serial.begin(9600);
  miServo.attach(9); // Conectamos el servo al pin 9 
  miServo.write(0);  // Iniciamos el servo en 0 grados
  delay(1000);
}

void loop() {
  valorLluvia = analogRead(pinSensor); // Leemos el sensor
  
  Serial.print("Lectura del sensor: ");
  Serial.println(valorLluvia);

  // Si el valor es menor al umbral, hay lluvia 
  if (valorLluvia < umbral) {
    Serial.println("¡Lluvia detectada! Girando a 180 grados.");
    // miServo.write(180); // Mueve el servo a 180 grados
    servo_to_180();
  } else {
    Serial.println("Seco. Regresando a 0 grados.");
    // miServo.write(0);   // Regresa a 0 grados
    servo_to_0();
  }

  delay(500); // Pausa para estabilidad 
}

void servo_to_0(){
if(servoPosition == 0) return;

for (int i = 180; i >= 0;i--){
  servoPosition= i;
  miServo.write(i);
  delay(20);
}
}


void servo_to_180(){
if(servoPosition == 180) return;

for (int i = 0; i<= 180;i++){
  servoPosition= i;
  miServo.write(i);
  delay(20);
}}

