#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>


/*
   This sample sketch demonstrates the normal use of a TinyGPSPlus (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
int k=0;

String temp="okkkkk";
// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
SoftwareSerial mySerial(A3, A4);


void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);



  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPSPlus with an attached GPS module"));
  Serial.print(F("Testing TinyGPSPlus library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();
}

void loop()
{





  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
  {
    if (gps.encode(ss.read()))
    {
      displayInfo();
  k++;


  {

    k=0;
    ss.end();
    
  mySerial.begin(9600);

char * tab2 = new char [temp.length()+1];
strcpy (tab2, temp.c_str());

  

    mySerial.write((byte) 11);
    mySerial.write((byte) 22);
    mySerial.write((byte) 1);
    mySerial.write(tab2);
    

      mySerial.end();
   
    ss.begin(9600);
  }

      
    }
  }

Serial.println("ok1");
      




}

void displayInfo()
{


  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {

    temp=String(gps.location.lat(), 6);
    Serial.print("temp data:   ");
    Serial.println(temp);
    temp+=" ,";
    Serial.print(gps.location.lat(), 6);
    temp+=String(gps.location.lng(), 6);
    //temp+="\r\n";
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();


}
