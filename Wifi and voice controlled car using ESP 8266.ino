#define BLYNK_TEMPLATE_ID "TMPLG00bXgLY"
#define BLYNK_DEVICE_NAME "Micro Project"
#define BLYNK_AUTH_TOKEN "j5cUH0x-s81V-s-N4ZndOlLLTSdJKSBH"
#define BLYNK_PRINT Serial
#include "NewPing.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGER_PIN D7
#define ECHO_PIN D8
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
bool forward = 0; bool backward = 0; bool left = 0; bool right = 0; int Speed = 255;
char auth[] = BLYNK_AUTH_TOKEN ;
char ssid[] = " Galaxy F62";
char pass[] = "bxpg6164";
BLYNK_WRITE(V0)
{
Speed = param.asInt();
Serial.println(Speed);
}
BLYNK_WRITE(V1)
{
forward = param.asInt();
}
BLYNK_WRITE(V2)
{
backward = param.asInt();
}
BLYNK_WRITE(V3)
{
left = param.asInt();
}
BLYNK_WRITE(V4)
{
right = param.asInt();
}
BLYNK_WRITE(V5)
{
Serial.println("Forward_voice");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, HIGH);
digitalWrite(D2, LOW);
digitalWrite(D3, HIGH);
digitalWrite(D4, LOW);
delay(5000);
}
BLYNK_WRITE(V6)
{
Serial.println("Backward_voice");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, LOW);
digitalWrite(D2, HIGH);
digitalWrite(D3, LOW);
digitalWrite(D4, HIGH);
delay(5000);
}
BLYNK_WRITE(V7)
{
Serial.println("Left_voice");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, LOW);
digitalWrite(D2, LOW);
digitalWrite(D3, HIGH);
digitalWrite(D4, LOW);
delay(5000);
}
BLYNK_WRITE(V8)
{
Serial.println("Right_voice");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, HIGH);
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
delay(5000);
}
void carcontrol()
{
if (forward == 1)
{
car_forward();
}
else if (backward == 1)
{
car_backward();
}
else if (left == 1)
{
car_left();
}
else if (right == 1)
{
car_right();
}
else
{
car_stop();
}
}
void setup()
{
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
pinMode(D1, OUTPUT); // left in1
pinMode(D2, OUTPUT); // left in2
pinMode(D3, OUTPUT); // right in1
pinMode(D4, OUTPUT); // right in2
pinMode(D5, OUTPUT);//right motor speed
pinMode(D0, OUTPUT);
}
void loop()
{
Blynk.run();
if (sonar.ping_cm() <= 7){
Serial.print("Ultra-Override: ");
Serial.println(sonar.ping_cm());
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, LOW);
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
}
else{
carcontrol();
}
}
void car_forward()
{
Serial.println("forward");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, HIGH);
digitalWrite(D2, LOW);
digitalWrite(D3, HIGH);
digitalWrite(D4, LOW);
}
void car_backward()
{
Serial.println("backward");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, LOW);
digitalWrite(D2, HIGH);
digitalWrite(D3, LOW);
digitalWrite(D4, HIGH);
}
void car_left()
{
Serial.println("left");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, LOW);
digitalWrite(D2, LOW);
digitalWrite(D3, HIGH);
digitalWrite(D4, LOW);
}
void car_right()
{
Serial.println("right");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, HIGH);
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
}
void car_stop()
{
Serial.println("stop");
analogWrite(D0, Speed);
analogWrite(D5, Speed);
digitalWrite(D1, LOW);
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
}
