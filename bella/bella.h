#ifndef bella_H
#define bella_H

#include <Arduino.h>
#include <String.h>

typedef enum  {
        COMMON_CATHODE = 0,
        COMMON_ANODE = 1,
} common_type;

typedef enum {

  RGB_OUTPUT = 1,
  RGB_INPUT = 0,

} mode_type;

class RGB {
public:
int redpin;
int greenpin;
int bluepin;

int r_val;
int g_val;
int b_val;

int redMap;
int greenMap;
int blueMap;
common_type commonType;
mode_type modeType;

RGB(int rpin,int gpin,int bpin,common_type commonType);

void setMode(mode_type modeType);
void setColor(int red,int green,int blue);
void setRed(int red);
void setGreen(int green);
void setBlue(int blue);
int valueMap(int value);
void turnRGBoff(bool stat);
void setColor(String str);

};


#endif
