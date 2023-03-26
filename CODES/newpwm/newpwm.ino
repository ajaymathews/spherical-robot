#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "80ccde0a6d5749bd97291f1967b8b900";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "12345689";
int speed1;
Servo myservo;
void setup() {
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass); 
 myservo.attach(2);
 pinMode(D1,OUTPUT);
 pinMode(D2,OUTPUT);
 pinMode(D5,OUTPUT);
 pinMode(D6,OUTPUT);
 pinMode(D7,OUTPUT);
 pinMode(D8,OUTPUT);
 pinMode(D4,OUTPUT);//servo
}
BLYNK_WRITE(V2) {
  speed1 = param.asInt();
  analogWrite(D1,speed1);
  analogWrite(D2,speed1);
  Serial.println(speed1);
}
BLYNK_WRITE(V0)
{
  int x = param[0].asInt();
  Serial.print("X = ");
  Serial.println(x);
  if(x==1)
 {
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  digitalWrite(D8,HIGH);
  }
  else if(x==0)
  {
  digitalWrite(D5,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,HIGH);
  digitalWrite(D8,LOW);
  }
}
BLYNK_WRITE(V1)
{
  int pos = param.asInt();
  myservo.write(pos); 
}
void loop() {

 Blynk.run();

}
