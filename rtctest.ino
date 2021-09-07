#include "RTC_SAMD51.h"
#include "DateTime.h"
#include "TFT_eSPI.h"


TFT_eSPI tft;
RTC_SAMD51 rtc;

void setup()
{
    rtc.begin();
    DateTime now = DateTime(F(__DATE__), F(__TIME__));
    tft.begin();
    tft.setRotation(3);
    tft.setTextSize(3);
    tft.fillScreen(TFT_BLACK);
    rtc.adjust(now);
}

String datetimeZeroPad(String s){
  return s.length() == 1 ? "0" + s : s;
}


void loop(){ 
  
    DateTime now = rtc.now();
    tft.drawString("JST: " + String(now.year()) + "/" + datetimeZeroPad(String(now.month())) + "/" + datetimeZeroPad(String(now.day())), 20, 20);
    tft.drawString(datetimeZeroPad(String(now.hour())) + ":" + datetimeZeroPad(String(now.minute())) + ":" + datetimeZeroPad(String(now.second())), 145, 50);

    DateTime eat(now - TimeSpan(0, 6, 0, 0));
    tft.drawString("EAT: " + String(eat.year()) + "/" + datetimeZeroPad(String(eat.month())) + "/" + datetimeZeroPad(String(eat.day())), 20, 90);
    tft.drawString(datetimeZeroPad(String(eat.hour())) + ":" + datetimeZeroPad(String(eat.minute())) + ":" + datetimeZeroPad(String(eat.second())), 145, 120);

    delay(1000);
}
