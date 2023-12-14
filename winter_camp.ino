#include <Servo.h>
#include <Servo.h>
#include <SoftwareSerial.h>
int xposPin = A0;         // 雙軸按鍵搖桿 VRx 接 Arduino Analog pin A0
int yposPin = A1;         // 雙軸按鍵搖桿 VRy 接 Arduino Analog pin A1
int Xpos = 0;             // 定義X軸伺服器位址參數
int Ypos = 0;             // 定義丫軸伺服器位址參數
int buttonPin = 7;        // 搖桿按鍵輸出 SW 接 Arduino pin 7
int buttonPress = 0;      // 定義 Arduino 從搖桿按鍵 SW 讀入值為 buttonPress 
Servo arm_1;
Servo arm_2;
int servoPin_1 = 2;
int serrvoPin_2 = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);     
  digitalWrite(buttonPin,HIGH); 
  Serial.print('Start');
  arm_1.attach(servoPin_1);  
  arm_1.write(90);
  arm_2.attach(serrvoPin_2);
  arm_2.write(90);
}

void loop () {
  buttonPress = digitalRead(buttonPin);
  pushAmmo();
  delay(50);
}

void pushAmmo(){

  Xpos = analogRead(xposPin);            // 讀入搖桿 x 軸數值，0-1023
  Ypos = analogRead(yposPin);            //讀入搖桿 y 軸 數值，0-1023

  if((Xpos < 600 && Xpos > 500) && (Ypos < 600 && Ypos > 500)) {

  }
  else {
    arm_1.write(30);
    arm_2.write(270);
    delay(500);

    arm_1.write(270);
    arm_2.write(30);
    delay(500);
  }
}