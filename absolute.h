#ifndef ABSOLUTE_H
#define ABSOLUTE_H

#include "mbed.h"

class absolute {
private:
  int save, value, result;
  DigitalIn data0, data1, data2, data3, data4, data5, data6, data7;

public:
  absolute(PinName pin0, PinName pin1, PinName pin2, PinName pin3, PinName pin4,
           PinName pin5, PinName pin6, PinName pin7);

  int getAngre();
};

#endif