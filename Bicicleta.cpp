#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
//Desing de cada parte da bike em bytes/bits
byte bodyupRight[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11000,
    B01000,
    B11000,
};
byte bodyupLeft[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00011,
    B00001,
};

byte bodyup[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
};

byte leftup[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};

byte bodyDown[8] = {
    B10000,
    B01010,
    B00101,
    B11010,
    B00000,
    B00000,
};
byte leftwheel[8] = {
    B00001,
    B00011,
    B01110,
    B10001,
    B10111,
    B10001,
    B10001,
    B01110,
};
byte rightwheel[8] = {
    B10000,
    B11000,
    B01110,
    B10001,
    B10001,
    B10001,
    B10001,
    B01110,
};
byte dusttrait[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00110,
    B11000,
};
byte dusttraitline[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01110,
};
byte lightning[8] = {
  B00100,  //   X  
  B01100,  //  XX  
  B01100,  //  XX  
  B11110,  // XXXXX
  B00111,  //   XXX
  B00110,  //   XX 
  B01100,  //  XX  
  B01000   //  X   
};
void setup()
{
  //Posicionamento e Desing Inicial do LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Eletric Boys");
  lcd.setCursor(6, 1);
  lcd.print("Bike");
  lcd.createChar(12, lightning);
  lcd.setCursor(4,1);
  lcd.write(byte(12));  
  lcd.setCursor(11,1);
  lcd.write(byte(12));  
  delay(3000);
  lcd.clear();
  //Criacao de Custom Char Byte para armazenar o posicionamento dos bits
  lcd.createChar(0, leftwheel);
  lcd.createChar(1, rightwheel);
  lcd.createChar(2, leftup);
  lcd.createChar(3, bodyDown);
  lcd.createChar(4, bodyup);
  lcd.createChar(5, bodyupRight);
  lcd.createChar(6, bodyupLeft);
  lcd.createChar(7, dusttrait);
  lcd.createChar(10, dusttraitline);
  
}
//Criacao dos Vetores
int LeftWheelVector[2] = {0, 1};
int RightWheelVector[2] = {2, 1};
int BodyUpVector[2] = {1, 0};
int RightleftupVector[2] = {0, 0};
int BodyDownVector[2] = {1, 1};
int BodyUpRightVector[2] = {2, 0};
int BodyUpLeftVector[2] = {0, 0};
int DustTrait[2] = {-1, 1};
int DustTraitLine[2] = {-2, 1};

void loop()
{
    //Iteracao para movimento da bike
  for (int i = 0; i < 16; i++)
  {

    lcd.noDisplay();
    // leftWheel
    lcd.display();
    lcd.setCursor(LeftWheelVector[0] + i, LeftWheelVector[1]);
    lcd.write(byte(0));
    // rightwheel
    lcd.setCursor(RightWheelVector[0] + i, RightWheelVector[1]);
    lcd.write(byte(1));
    // leftup
    lcd.setCursor(BodyUpLeftVector[0] + i, BodyUpLeftVector[1]);
    lcd.write(byte(2));
    // body
    lcd.setCursor(BodyDownVector[0] + i, BodyDownVector[1]);
    lcd.write(byte(3));
    // bodyup
    lcd.setCursor(BodyUpVector[0] + i, BodyUpVector[1]);
    lcd.write(byte(4));
    // bodyupRight
    lcd.setCursor(BodyUpRightVector[0] + i, BodyUpRightVector[1]);
    lcd.write(byte(5));
    // bodyupLeft
    lcd.setCursor(BodyUpLeftVector[0] + i, BodyUpLeftVector[1]);
    lcd.write(byte(6));
    // dustTrait
    lcd.setCursor(DustTrait[0] + i, DustTrait[1]);
    lcd.write(byte(7));
    // dustTraitLine
    lcd.setCursor(DustTraitLine[0] + i, DustTraitLine[1]);
    lcd.write(byte(10));

    lcd.setCursor(1, 0);
    delay(1000 - (i * 65));
    lcd.clear();
  }
}
