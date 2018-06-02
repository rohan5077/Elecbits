#include <LiquidCrystal.h>

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

LiquidCrystal lcd(13, 12, 11,10,9,8);

int hh,mm,sec,dd,mon,yy;
float lati,lon;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  ss.begin(GPSBaud);
  lcd.setCursor(0,0);
  lcd.print("GPS Digital CLK");
  lcd.setCursor(3,1);
  lcd.print(" Elecbits ");
  delay(1000);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      lati = gps.location.lat();
      lon = gps.location.lng();      
      hh = gps.time.hour()+5;
      mm = gps.time.minute();
      sec = gps.time.second();
      yy = gps.date.year();
      mon = gps.date.month();
      dd = gps.date.day();
      
      lcd.clear();
      gpsDate();
      gpsTime();
      delay(4000);
      lcd.clear();
      gpsCord();
      delay(4000);
    }
    
  }
}

void gpsTime(void){
      if(hh>23)
        hh = 24-hh;
      if (mm>29)
        mm = mm-30;
      else
        mm = mm+30;

      Serial.print("Time: ");  
      Serial.print(hh); // Hour (0-23) (u8)
      Serial.print(":");
      Serial.print(mm); // Minute (0-59) (u8)
      Serial.print(":");
      Serial.println(sec); // Second (0-59) (u8)

      // Time in hh:mm:ss format on LCD

      lcd.setCursor(0,1);
      lcd.print("Time: ");
      lcd.setCursor(5,1);
      lcd.print(hh);
      lcd.print(":");
      lcd.print(mm);
      lcd.print(":");
      lcd.print(sec);
}

void gpsDate(){
  Serial.print("Date: ");
  Serial.print(dd);// date (2000+) (u16)
      Serial.print(":");
      Serial.print(mon); // Month (1-12) (u8)
      Serial.print(":");
      Serial.println(yy); // year (1-31) (u8)

      // Date in dd/mm/yyyy format
      
      lcd.setCursor(0,0);
      lcd.print("Date: ");
      lcd.setCursor(5,0);
      lcd.print(dd);
      lcd.print("/");
      lcd.print(mon);
      lcd.print("/");
      lcd.print(yy);
}

void gpsCord(void){
  Serial.print("Latitude= ");       
      Serial.print(lati, 6);
      Serial.print(" Longitude= "); 
      Serial.println(lon, 6);   

      // Latitude and Longitude

      lcd.setCursor(0,0);
      lcd.print("Latitude:  ");
      lcd.print(lati);
      lcd.setCursor(0,2);
      lcd.print("Longitude: ");
      lcd.print(lon);
  
}

