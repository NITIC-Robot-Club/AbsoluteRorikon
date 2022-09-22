#include "absolute.h"
#include "mbed.h"

absolute::absolute(PinName pin0, PinName pin1, PinName pin2, PinName pin3,
                   PinName pin4, PinName pin5, PinName pin6, PinName pin7)
    : data0(pin0), data1(pin1), data2(pin2), data3(pin3), data4(pin4),
      data5(pin5), data6(pin6), data7(pin7){};

int absolute::getAngre() {
  int save, value, result;
  int getData[8] = {
      data0.read() ^ 1, data1.read() ^ 1, data2.read() ^ 1, data3.read() ^ 1,
      data4.read() ^ 1, data5.read() ^ 1, data6.read() ^ 1, data7.read() ^ 1,
  };
  result = getData[7] << 7;
  save = getData[7];
  for (int i = 6; i >= 0; i--) {
    value = save ^ getData[i];
    result = result | (value << i);
    save = value;
  }
  return result;
};
