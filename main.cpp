#define LINES_NUMBER 31

#include <LiquidCrystal.h>

const char *lines[LINES_NUMBER] = {
  "First things",
  "first!!!!!!",
  "Ima say all",
  "the words inside",
  "my head",
  "Im fired up",
  "and tired of",
  "The way that",
  "things have been",
  "Oh--Oooooh",
  "The way that",
  "things have been",
  "Oh--Oooooh",
  "Second thing",
  "Second!!!",
  "Dont you tellME",
  "what you think",
  "that I could be",
  "Im the one",
  "at the sail",
  "Im the master",
  "of my sea",
  "Oh--Oooooh",
  "The master",
  "of my sea",
  "Oh--Oooooh",
  "Pain!",
  "You made me a",
  "You made me a",
  "Believer!!",
  "Believer!!"
};

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  lcd.blink();
}

void loop() {
  int flg = 2;
  for (int i = 0; i < LINES_NUMBER; i++) {
    typeWriting(lines[i], int(strlen(lines[i])), flg%2);
    delay(1000);
    flg ++;
    if (flg > 2) {
      flg = 1;
    }
  }
}

void typeWriting(char *str, int len, int rw) {
  clearRow(rw, true);
  for (int i = 0;i<len;i++) {
    char* tmp = new char[i+2];
    for(int q = 0; q < i+1; q++) {
      tmp[q] = str[q];
    }
    tmp[i+1] = '\0';
    clearRow(rw, false);
    lcd.setCursor(0, rw);
    lcd.print(tmp);
    delete tmp;
    delay(50);
  }
}

void clearRow(int rw, bool wait) {
  for (int i = 15; i >=0;i--){
    lcd.setCursor(i, rw);
    lcd.print("_");
    if (wait) {
      delay(10);
    }
  }
}
