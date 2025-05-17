#include <Arduino.h>

#include <M5Unified.h>
#include <Avatar.h>

M5Canvas canvas(&M5.Lcd);
using namespace m5avatar;

//Avatar avatar(&M5.Display, 320, 240);
Avatar *avatar; //(&M5.Display, 640, 480);


const Expression expressions[] = {
  Expression::Angry,
  Expression::Sleepy,
  Expression::Happy,
  Expression::Sad,
  Expression::Doubt,
  Expression::Neutral
};
const int expressionsSize = sizeof(expressions) / sizeof(Expression);
int idx = 0;

ColorPalette* cps[4];
const int cpsSize = sizeof(cps) / sizeof(ColorPalette*);
int cpsIdx = 0;

bool isShowingQR = false;

void setup()
{
  auto cfg = M5.config();
  M5.begin(cfg);
  M5.Lcd.setRotation(0);
  M5.Lcd.setBrightness(80);
  M5.Lcd.clear();
  M5.Lcd.setTextSize(3);
  M5.Lcd.setFont(&fonts::efontJA_24_bi);
  canvas.createSprite(M5.Display.width(), M5.Display.height());
  canvas.setColorDepth(16);
  canvas.fillScreen(TFT_YELLOW);
  canvas.setCursor(M5.Display.width() / 2, M5.Display.height() / 2);
  canvas.setFont(&fonts::efontJA_24_bi);
  canvas.println("M5Stack Avatar Test");
  canvas.println("回転テスト");
  canvas.setPivot(M5.Display.width() / 2, M5.Display.height() / 2);

  cps[0] = new ColorPalette();
  cps[1] = new ColorPalette();
  cps[2] = new ColorPalette();
  cps[3] = new ColorPalette();
  cps[1]->set(COLOR_PRIMARY, TFT_YELLOW);
  cps[1]->set(COLOR_BACKGROUND, TFT_DARKCYAN);
  cps[2]->set(COLOR_PRIMARY, TFT_DARKGREY);
  cps[2]->set(COLOR_BACKGROUND, TFT_WHITE);
  cps[3]->set(COLOR_PRIMARY, TFT_RED);
  cps[3]->set(COLOR_BACKGROUND, TFT_PINK);
  //avatar = new Avatar(&M5.Display, M5.Display.width(), M5.Display.height());
  avatar = new Avatar(&M5.Display, 720, 720); //M5.Display.width(), M5.Display.height());

  avatar->init(1);
  avatar->setColorPalette(*cps[1]);
  avatar->setScale(1.0f);
  //avatar->setRotation(180);
  //avatar.setPosition(M5.Lcd.height() / 2, M5.Lcd.width() / 2);
  //avatar.setPosition(200, 400);

}


// ********************************
// 下記のROTATION_TESTを有効にすると、回転テストが実行されます。(Tab5だと再起動を繰り返す。)
//#define ROTATION_TEST

int16_t rotation = 0;
void loop()
{
  M5.update();
#ifdef ROTATION_TEST
  avatar->setRotation(rotation);
  rotation = (rotation + 1);
  delay(10);
  if (rotation > 360) {
    rotation = 0;
  }
#endif
//  rotation = (rotation + 1) % 4;
//  M5.Display.setRotation(rotation);
//  M5.Display.clear();
//  delay(2000);
  //canvas.pushSprite(0, 0);
}
