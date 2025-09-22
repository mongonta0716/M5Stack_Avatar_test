#include <Arduino.h>

#include <M5Unified.h>

M5Canvas canvas(&M5.Lcd);

void setup()
{
  auto cfg = M5.config();
  M5.begin(cfg);
  M5.Lcd.setRotation(1);
  M5.Lcd.setBrightness(80);
  M5.Lcd.clear();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setFont(&fonts::efontJA_24_bi);
  M5.Lcd.println("M5Stack Avatar Test");
  delay(2000);
  canvas.setColorDepth(1);
  canvas.createSprite(100, 50);
  canvas.setCursor(0,0);//M5.Display.width() / 2, M5.Display.height() / 2);
  canvas.setTextSize(2);
  canvas.println("M5Stack Avatar Canvas Test");
  canvas.pushSprite(0, 0);
  delay(2000);

}


void loop()
{
  delay(100);
}
