#include <LiquidCrystal.h>
#include <dht.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LCD pins setup:
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

dht DHT;
// DHT sensor defined on AnalogOut pin7
#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);


}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature); Serial.println(" C");
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity); Serial.println(" %");
  // Temperature & Humidity data also outputs to the serial terminal

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
// Default temperatures displayed in degrees Celsius (C)
  lcd.print((int)(DHT.temperature)); lcd.print(" C");
  /*  For temperatures displayed in degrees Fahrenheit (F):
   lcd.print((int)((1.8)*(int)(DHT.temperature) + (int)(32))); lcd.print(" F");
  */
  
  lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print((int)(DHT.humidity));lcd.print(" %");
 delay(1200); // Set delay time (ms) between data samples
}
