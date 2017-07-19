

#include <bella.h>

RGB::RGB( int rpin, int gpin, int bpin, common_type type)
{
        redpin = rpin;
        greenpin = gpin;
        bluepin = bpin;
        commonType = type;

}


void RGB::setMode(mode_type mtype)
{
  Serial.begin(9600);
  modeType = mtype;

        if (modeType==1)
        {
                pinMode(redpin,OUTPUT);
                pinMode(greenpin,OUTPUT);
                pinMode(bluepin,OUTPUT);
        }

        else if(modeType==0)
          {

          digitalWrite(redpin,LOW);
          digitalWrite(greenpin,LOW);
          digitalWrite(bluepin,LOW);

          Serial.println("RGB led common error:: A RGB LED cannot use as a input!! ");

        }
}

void RGB::setColor(int red,int green, int blue)
{
        setRed(red);
        setGreen(green);
        setBlue(blue);
}

void RGB::setRed(int red)
{
        r_val = red;
        redMap = valueMap(r_val);
        analogWrite(redpin,redMap);

}

void RGB::setGreen(int green)
{
        g_val = green;
        greenMap = valueMap(g_val);
        analogWrite(greenpin,greenMap);

}

void RGB::setBlue(int blue)
{
        b_val = blue;
        blueMap = valueMap(b_val);
        analogWrite(bluepin,blueMap);
}


int RGB::valueMap(int value)
{
        value = (value < 0) ? 0 : (value > 255) ? 255 : value;
        value = (commonType == COMMON_ANODE) ? 255-value : value;
        return value;
}

void RGB::turnRGBoff(bool stat)
{
  if(stat == true)
  {
  setBlue(0);
  setRed(0);
  setGreen(0);
}
else
{
//nothing to do
}


}

void RGB::setColor(String str)
{



if(str=="auto")
{

     int redclr = random(0,255);
     int greenclr = random(0,255);
     int blueclr = random(0,255);
     setRed(redclr);
     setGreen(greenclr);
     setBlue(blueclr);
}
else
{
  //nothing
}

}
