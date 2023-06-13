#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>
#include <iostream>
using namespace std;

int score;
int leftButton = 4;
int rightButton = 5;
volatile bool leftButtonFlag = 0;
volatile bool rightButtonFlag = 0;

float midi[127];
int A_four = 440;
int c_major[8] = {60, 62, 64, 65, 67, 69, 71, 72};
int victory[4][2] = {
  {69, 400},
  {62, 400},
  {69, 200},
  {72, 400},
};
int incorrect[1][2] = {
  {65, 500},
};

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Welcome to Simon Says! This game is about hitting the right buttons when the colors come on screen. Red means the left button, blue means the right. Try to get a high score!");
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
  pinMode(leftButton, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(leftButton), redHit, FALLING);
  pinMode(rightButton, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(rightButton), blueHit, FALLING);
}


void loop() {
  delay(2000);
  for(int i = 0; i <= 20; i++);
  {
    int blueFlashLevelOne;
    if (redHit){
      ++score;
    }
    if (blueHit){
      ++score;
    }
  }
  for(int i = 0; i < sizeof(victory) / sizeof(victory[0]); i++)
    {
      CircuitPlayground.playTone(midi[victory[i][0]], victory[i][1]);
      Serial.println(midi[victory[i][0]]);
      delay(1);
    }
  delay(5000);
  for(int i = 0; i <= 10; i++);
  {
    int LED_num = random(10);
    int blueFlashLevelTwo;
    int redFlashLevelTwo;
    if (redHit){
      ++score;
    }
    if (blueHit){
      ++score;
    }
  }
  for(int i = 0; i < sizeof(victory) / sizeof(victory[0]); i++)
    {
      CircuitPlayground.playTone(midi[victory[i][0]], victory[i][1]);
      Serial.println(midi[victory[i][0]]);
      delay(1);
    }
  delay(5000);
  for(int i = 0; i <= 100; i++);
  {
    int blueFlashLevelThree;
    int redFlashLevelThree;
    if (redHit){
      ++score;
    }
    if (blueHit){
      ++score;
    }
  }
  for(int i = 0; i < sizeof(victory) / sizeof(victory[0]); i++)
    {
      CircuitPlayground.playTone(midi[victory[i][0]], victory[i][1]);
      Serial.println(midi[victory[i][0]]);
      delay(1);
    }
  delay(5000);
}
void redFlashLevelOne()
{
  int LED_num = random(10);
  CircuitPlayground.setPixelColor(LED_num, 255, 0, 0);
  delay(1000);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
  delay(1000);
}
void redFlashLevelTwo()
{
  int LED_num = random(10);
  CircuitPlayground.setPixelColor(LED_num, 255, 0, 0);
  delay(500);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
  delay(500);
}
void redFlashLevelThree()
{
  int LED_num = random(10);
  CircuitPlayground.setPixelColor(LED_num, 255, 0, 0);
  delay(300);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
  delay(300);
}
void blueFlashLevelOne()
{
  int LED_num = random(10);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 255);
  delay(1000);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
  delay(1000);
}
void blueFlashLevelTwo()
{
  int LED_num = random(10);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 255);
  delay(500);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
  delay(500);
}
void blueFlashLevelThree()
{
  int LED_num = random(10);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 255);
  delay(300);
  CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
  delay(300);
}
void redHit()
{
  leftButtonFlag = 1;
}

void blueHit()
{
  rightButtonFlag = 1;
}

