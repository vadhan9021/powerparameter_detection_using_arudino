

#include <LiquidCrystal.h>
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int relay=9;
int buzzer=8;
int Power;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Power ParameterDetction");
  lcd.setCursor(0, 1);
  lcd.print("Using Arduino");
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(relay, LOW);
  delay(9000);
  lcd.clear();
}

void loop() {
  char str[1];
  sensorValue = analogRead(A0);
   //Serial.print("ADC Value=");
  //Serial.println(sensorValue);
  delay(10); 
  float current=sensorValue*0.0046;
  Power=current*230;
  sprintf(str, "%03d", Power);
  lcd.setCursor(0, 0);
  lcd.print("V=230 V");
  lcd.setCursor(8, 0);
  lcd.print("I=");
  lcd.setCursor(15, 0);
  lcd.print("A");
  lcd.setCursor(10, 0);
  lcd.print(current);
  lcd.setCursor(0, 1);
  lcd.print("Power=");
  lcd.setCursor(11, 1);
  lcd.print("W");
  lcd.setCursor(7, 1);
  lcd.print(str);
  Serial.print("current=");
  Serial.println(current);
  Serial.print("Power=");
  Serial.println(Power);
 
  //Serial.println(outputValue);
   if(Power>250)
    {
      while(1)
      {
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("  Power Theft   ");
     lcd.setCursor(0, 1);
     lcd.print("    Detected   ");
     digitalWrite(buzzer, HIGH);
     digitalWrite(relay, HIGH);
     Serial.println("Power is cut off due Power Theft");
      }
    
    }
    else
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, LOW);
    Serial.println("Power is Normal");
    delay(500);
}
