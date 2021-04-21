/*
=======================================================

 *************  https://github.com/vinojv96/  *********

=======================================================
*/
 * / CONNECTIONS:
// DS1307 SDA --> SDA A4
// DS1307 SCL --> SCL A5
// DS1307 VCC --> 5V
// DS1307 GND --> GND
* Relay IN --> D2
*/
#include "RTClib.h"

RTC_DS1307 rtc;
int Relay = 2;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const int OnHour = 18;
const int OnMin = 15;
const int OffHour = 20;
const int OffMin = 00;

void setup() {
  Serial.begin(115200);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);

}

void loop() {
char buf1[20];
DateTime now = rtc.now();
sprintf(buf1, "%02d:%02d:%02d %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());
Serial.print(F("Date/Time: "));
Serial.println(buf1);
  delay (3000);
  
   if(now.hour() == OnHour && now.minute() == OnMin) 
  {
    digitalWrite(Relay,LOW);
    Serial.println("LIGHT ON");
    }
    else if(now.hour() == OffHour && now.minute() == OffMin){
      digitalWrite(Relay,HIGH);
      Serial.println("LIGHT OFF");
       
    }
}