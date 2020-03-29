#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x3F for a 16 chars and 2 line display // note: it may be different for your LCD please find it.
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#include <DS1302.h>
// Init the DS1302
DS1302 rtc(2, 3, 4);  // Rst, Data, Clk
// Init a Time-data structure
Time t;

void setup()
{
  // Enable when clock must be inistialized initClock();
 
  lcd.init();
  lcd.backlight();
}

void initClock() {
 // Set the clock to run-mode, and disable the write protection
 rtc.halt(false);
 rtc.writeProtect(false);

 rtc.setDOW(SUNDAY);
 rtc.setTime(21, 51, 00); // Set the time to 24hr format it will automatically take time according to AM/PM
 rtc.setDate(29, 3, 2021); 
}

void printDayOfWeek() {
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
}

void printDate() {
  lcd.setCursor(6, 0);
  lcd.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, '/'));
}

void printTime() {
  lcd.setCursor(4, 1);
  lcd.print(rtc.getTimeStr());
}

void print() {
  lcd.setCursor(0, 0);
  lcd.print(t.sec, DEC);
}

void loop()
{
  t = rtc.getTime(); 
  printDayOfWeek();
  printDate();
  printTime();
  delay (1000);
  lcd.clear();
}
