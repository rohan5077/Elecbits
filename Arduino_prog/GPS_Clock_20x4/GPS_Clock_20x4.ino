#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

char str[70];
char *test="$GPRMC";
int temp,i;
  
static const int RXPin = 10, TXPin = 9;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GPS CLOCK");
  lcd.setCursor(0,1);
  lcd.print("By : Saad mohd");
  lcd.setCursor(0,2);
  lcd.print("Raunak Singh &");
  lcd.setCursor(0,3);
  lcd.print("Rajat Singh kalra");
  delay(6000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Date:");
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(0,2);
  lcd.print("Latitude:");
  lcd.setCursor(0,3);
  lcd.print("Longitude:");
  
}

void loop()
{
  ssEvent();


  if(temp) 
    {
      int str_lenth=i;
      int x=0,comma=0;
      String UTC_hour="";
      String UTC_minut="";
      String UTC_second="";
      String UTC_date="";
      String UTC_month="";
      String UTC_year="";
      String str1="";
      while(x<str_lenth)
        {
          if(str[x]==',')
          comma++;
          if(comma==1)
            {
              x++;
              UTC_hour+=str[x++];
              UTC_hour+=str[x++];
              UTC_minut+=str[x++];
              UTC_minut+=str[x++];
              UTC_second+=str[x++];
              UTC_second+=str[x];
              comma=2;
            }
          if(comma==10)
            {
              x++;
              UTC_date+=str[x++];
              UTC_date+=str[x++];
              UTC_month+=str[x++];
              UTC_month+=str[x++];
              UTC_year+=str[x++];
              UTC_year+=str[x];
            }  
          x++;
        }
      int UTC_hourDec=UTC_hour.toInt();
      int UTC_minutDec=UTC_minut.toInt();
      int Second=UTC_second.toInt();
      int Date=UTC_date.toInt();
      int Month=UTC_month.toInt();
      int Year=UTC_year.toInt();
      int Hour=UTC_hourDec+6;
      if(Hour>23)
        {
          Hour-=24;
          Date+=1;
        }
      int Minut=UTC_minutDec+30;
      if(Minut>59)
        Minut-=60;

      lcd.setCursor(6,0);
      lcd.print(Date);
      lcd.print("/");
      lcd.print(Month);
      lcd.print("/");
      lcd.print("20");
      lcd.print(Year);
     
      lcd.setCursor(6,1);
      lcd.print(Hour);
      lcd.print(":");
      lcd.print(Minut);
      lcd.print(":");
      lcd.print(Second);
      
      temp=0;
      i=0;
      x=0;
      str_lenth=0;
    }

  
  float temp_val;
  
  
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);  

  temp_val = gps.location.lat();
  lcd.setCursor(10,2);
  lcd.print(temp_val, 6);
   
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);

  temp_val = gps.location.lng();
  lcd.setCursor(11,3);
  lcd.print(temp_val, 6);
    
  smartDelay(1000);

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));
  
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())      
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

void ssEvent()
{
  while(1)
  {
    while (ss.available())         
      {
        char inChar = (char)ss.read();
        str[i]= inChar;                  
        i++;
        if (i < 7)                      
          {
            if(str[i-1] != test[i-1])    
              {
                i=0;
              }
          }
        if(i>65)
          {
            temp=1;
            break;
          }
      }
    if(temp)
      break;
  }
}
