#include <Servo.h> 
Servo myServo;

int ECO = 9;
int TRIG = 8;
int time;
int distance;
int SERVO = 7;

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECO,INPUT);
  pinMode(SERVO,OUTPUT);
  myServo.attach(SERVO);
  myServo.write(180);
  Serial.begin(9600);


}

void loop() {
  distance = getDistance();
  Serial.println("Distancia: " + String(distance) + " cm");

  if(distance <= 10){
    openDoor();
    delay(2000);
    closeDoor();
    delay(2000);
  }
}

int getDistance(){
  long duration;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECO, HIGH);
  distance = duration * 0.034 / 2;

  delay(500);
  return distance;
}


void openDoor(){
  for(int angle = 180; angle >=0; angle-=1){
    myServo.write(angle);
    delay(15);
  }

}

void closeDoor(){
  for(int angle= 0;angle <=180; angle +=1){
    myServo.write(angle);
    delay(15);
  }
}