#include<LiquidCrystal.h>
#define TEMP_0_PIN   13
#define a -5.03722995744685e-07
#define b 0.000854006989698572
#define c -0.579831442410260
#define d 244.313059688531
#define HEATER_0   10

int temp,i=50, u;
double x, y, e,P,I;
double calka=0;

LiquidCrystal lcd(16, 17, 23, 25, 27, 29);

void setup() {

  lcd.begin(20, 4);
  pinMode (HEATER_0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(13);
  x = (double)temp;
  y = a * x * x * x + b * x * x + c * x + d;
  lcd.setCursor(0, 0);
  lcd.print(y);
  if(y<175){
    analogWrite(HEATER_0,255);
    lcd.setCursor(0, 4);
    lcd.print(255);
  }
  else if(y<180){
    analogWrite(HEATER_0,200);
    lcd.setCursor(0, 4);
    lcd.print(200);
  }
  else if(y<200){
    analogWrite(HEATER_0,130);
    lcd.setCursor(0, 4);
    lcd.print(130);
  }
  else{
    analogWrite(HEATER_0,0);
    lcd.setCursor(0, 4);
    lcd.print(0);
  }
//e=100-y;
//if(y<100){
//  calka = calka+e*0.1;
//  
//  I= 0.1*calka;
//  
//}
//P=255/80*e;
// u=round(P+I);
// 
//if(u>255){
//  u=255;
//}
//
//if(u<0){
//  u=0; 
//}
//
// lcd.setCursor(0, 1);
//  lcd.print(P);
//  lcd.setCursor(0, 2);
//  lcd.print(I);

 //analogWrite(HEATER_0,u);
 //delay(100);
} 
