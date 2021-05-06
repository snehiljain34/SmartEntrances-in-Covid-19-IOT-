//Ultrasonic sensor for entrance #1 
const int pingPin =8; // Trigger Pin of Ultrasonic Sensor 
const int echoPin =10; // Echo Pin of Ultrasonic Sensor 
long duration, dist, distance; 
//handsfree sanitizer 
#include<Servo.h> 
int servo=13; 
int trigPinn=0; 
int echoPinn=1; 
long durationn; 
int distancee; 
Servo myservo; 
int pos=0; 
//Temperature sensor 
float temp; 
int tempPin = 0; 
//motion sensor 
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int sensor = 9; // the pin that the sensor is attached to 
int state = LOW; // by default, no motion detected 
int val = 0; 
int buzzer= 7; // the pin that the buzzer is attached to 
void setup() { 
 Serial.begin(9600); // Starting Serial Terminal 
 
 //ultrasonic sensor #1 
 pinMode(pingPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 
 
 //motion sensor 
 pinMode(sensor, INPUT); // initialize sensor as an input 
 pinMode(buzzer, OUTPUT); //initialize buzzer as an OUTPUT 
 lcd.begin(16, 2); 
 lcd.print("Hello"); 
 
 //handsfree sanitizer 
 pinMode(trigPinn, OUTPUT); 
 pinMode(echoPinn, INPUT);  myservo.attach(servo); 
 myservo.write(0); 
 
 
} 
void loop() { 
 digitalWrite(pingPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(pingPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(pingPin, LOW); 
 
 duration = pulseIn(echoPin, HIGH); 
 dist= duration*0.034/2; 
 distance=dist; 
 Serial.println(distance); 
 
 if (distance <125) 
 { 
 
 Serial.print("entrance="); 
 Serial.println(distance); 
 temp = analogRead(tempPin); 
 // read analog volt from sensor and save to variable temp 
 temp = temp * 0.48828125; 
 // convert the analog volt to its temperature equivalent 
 Serial.print("TEMPERATURE = "); 
 Serial.print(temp); // display temperature value 
 Serial.print("*C"); 
 Serial.println(); 
 delay(1000); // update sensor reading each one second 
 
 
 //handsfree sanitizer 
 digitalWrite(trigPinn, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPinn, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPinn, LOW); 
 durationn = pulseIn(echoPinn, HIGH); 
 distancee = durationn*0.034/2; 
 Serial.print("distancee"); 
 Serial.println(distancee); 
 if(distance<100){ 
 myservo.write(45);  delay(100); 
 myservo.write(90); 
 delay(100); 
 myservo.write(135); 
 delay(100); 
 myservo.write(180); 
 delay(1000); 
 myservo.write(0); 
 delay(3000); 
 } 
 else{ 
 Serial.println("move hands closer"); 
 } 
 
 //motion sensor 
 val = digitalRead(sensor); // read sensor value 
 if (val == HIGH) 
 { 
 delay(100); // delay 100 milliseconds 
 if (state == LOW) 
 { 
 lcd.setCursor(0, 1); 
 lcd.print("Motion Detected!"); 
 digitalWrite(buzzer, HIGH); // turn the LED/Buzz ON 
 state = HIGH; // update variable state to HIGH 
 } 
 } 
 else 
 { 
 delay(200); // delay 200 milliseconds 
 if (state == HIGH) 
 { 
 lcd.setCursor(0, 1); 
 lcd.print("Motion Stopped!"); 
 digitalWrite(buzzer, LOW); // turn the Buzzer ON 
 state = LOW; // update variable state to LOW 
 } 
 } 
 } 
 else 
 { 
 Serial.println("Come closer"); 
 delay(100); 
 } 
}
