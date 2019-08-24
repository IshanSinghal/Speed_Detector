#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sen1=8;
int sen2=9;
boolean active=0;
double calibrate=0;
 float time_for_speed=0;
float velocity;
void setup()
{
  lcd.begin(16, 2);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print(" Speed Detector ");
}

void loop() 
{
  calibrate=millis();
  if(digitalRead(sen1)==1)
 { while(digitalRead(sen2)!=1);
   time_for_speed= millis()- calibrate;
   while(digitalRead(sen2)!=0);
   velocity=288/time_for_speed; 
   active=1;
   
 } 
 if(active==1)
 {
      Serial.print("speed ");
      Serial.print(velocity);
      Serial.println("km/h");
      delay(800); 
      active=0;
   lcd.setCursor(3,1);
   lcd.print(velocity);
   lcd.print(" Km/hr   ");
   delay(500);
   lcd.setCursor(3,1);
   lcd.print("            ");
   delay(500);
  }  
  
}
