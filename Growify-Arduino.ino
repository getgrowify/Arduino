#include <SimpleDHT.h>

int msensor = A1;
int msvalue = 0;
int led = 13;

int led12 = 12;
int led11 = 11;
int led10 = 10;
int led9 = 9;

int blinker = 4;

boolean flag  = false;

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);
  pinMode(msensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(blinker, OUTPUT);
}

void loop() {
  
  
  digitalWrite(blinker, HIGH);
  delay(500);
  digitalWrite(blinker, LOW);
  delay(500);


  Serial.println("=================================");
  
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.println("Sensors: ");
  Serial.print("Temperature (*C) "); Serial.println((int)temperature);
  Serial.print("Humidity (%) "); Serial.println((int)humidity);
  msvalue = analogRead(msensor);
  float a = msvalue;
  float b = temperature;
  float c = humidity;

  float d = (a/1000)*100;
  Serial.print("Moisture (%) "); Serial.println(d);

  
  Serial.println(a+b+c);


  if (humidity == 60) {
    digitalWrite(led12, HIGH);
    digitalWrite(led11, HIGH);
    digitalWrite(led10, HIGH);
    digitalWrite(led9, HIGH);
  } else if (40 <= humidity <= 60) {
    digitalWrite(led12, HIGH);
    digitalWrite(led11, HIGH);
    digitalWrite(led10, HIGH);
    digitalWrite(led9, LOW);
  } else if (20 <= humidity <= 80) {
    digitalWrite(led12, HIGH);
    digitalWrite(led11, HIGH);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
  } else {
    digitalWrite(led12, HIGH);
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
  }
  delay(1500);
}
