#include <LiquidCrystal.h>

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

LiquidCrystal lcd(13, 12, 11,10,9,8);

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  ss.begin(GPSBaud);
  lcd.setCursor(0,0);
  lcd.print("GPS Digital Clock");
  lcd.setCursor(3,1);
  lcd.print(" Elecbits ");
  delay(1000);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      float lat = gps.location.lat();
      float lon = gps.location.lng();      
      int hh = gps.time.hour()+6;
      int mm = gps.time.minute();
      int ss = gps.time.second();
      int yy = gps.date.year();
      int mon = gps.date.month();
      int dd = gps.date.day();
      
      Serial.print("Latitude= ");       
      Serial.print(lat, 6);
      Serial.print(" Longitude= "); 
      Serial.println(lon, 6);

      if(hh>23)
        hh = 24-hh;
      if (mm>29)
        mm = mm-30;
      else
        mm = 30-mm;
        
      Serial.print(hh); // Hour (0-23) (u8)
      Serial.print(":");
      Serial.print(mm); // Minute (0-59) (u8)
      Serial.print(":");
      Serial.println(ss); // Second (0-59) (u8)
      Serial.print(yy);
      Serial.print(":");// Year (2000+) (u16)
      Serial.print(mon);
      Serial.print(":");// Month (1-12) (u8)
      Serial.println(dd); // Day (1-31) (u8)

      lcd.clear();
      
      // Date in dd/mm/yyyy format
      
      lcd.setCursor(0,0);
      lcd.print("Date: ");
      lcd.setCursor(5,0);
      lcd.print(dd);
      lcd.print("/");
      lcd.print(mon);
      lcd.print("/");
      lcd.print(yy);
      
      // Time in hh:mm:ss format
      
      lcd.setCursor(0,1);
      lcd.print("Time: ");
      lcd.setCursor(5,1);
      lcd.print(hh);
      lcd.print(":");
      lcd.print(mm);
      lcd.print(":");
      lcd.print(ss);
    }
  }
}

