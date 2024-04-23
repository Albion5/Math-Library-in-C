#include "s21_math.h"
double s21_frexp(double arg, int *exp) {
  sign sign = s21_signbit(arg);
  double base = 1.0;
  *exp = 0;
  if (s21_isnan(arg)) {
    base = sign == plus ? s21_nan : -s21_nan;
  } else if (s21_isinf(arg) || arg == 0) {
    base = arg;
  } else {
    unsigned long input = 0;
    for (int i = 0; i < 8; i++) {
      *(((unsigned char *)&input) + i) = *(((unsigned char *)&arg) + i);
    }
    *exp = ((input >> 52) & 0x7FF) - 1023 + 1;
    unsigned long mask = sign ? 0xBFF : 0x3FF;
    input &= ~((unsigned long)0xFFF << 52);
    input |= mask << 52;
    for (int i = 0; i < 8; i++) {
      *(((unsigned char *)&base) + i) = *(((unsigned char *)&input) + i);
    }
    base /= 2.0;
  }
  return base;
}