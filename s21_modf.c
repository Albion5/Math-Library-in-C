#include "s21_math.h"

double s21_modf(double x, double *x_int) {
  sign sign = s21_signbit(x);
  double x_fract = 0;
  if (s21_isnan(x)) {
    x_fract = sign == plus ? s21_nan : -s21_nan;
    *x_int = sign == plus ? s21_nan : -s21_nan;
  } else {
    unsigned long input = 0;
    for (int i = 0; i < 8; i++) {
      *(((unsigned char *)&input) + i) = *(((unsigned char *)&x) + i);
    }
    int exponent = ((input >> 52) & 0x7FF) - 1023;
    int fractional_bits = 52 - exponent;
    if (fractional_bits > 0 && fractional_bits <= 52) {
      unsigned long input_int = (__UINT64_MAX__ << fractional_bits) & input;
      for (int i = 0; i < 8; i++) {
        *(((unsigned char *)x_int) + i) = *(((unsigned char *)&input_int) + i);
      }
      x_fract = x - *x_int;
    } else if (fractional_bits <= 0) {
      *x_int = x;
      x_fract = 0;
      if (sign == minus) x_fract = -x_fract;
    } else {
      *x_int = 0;
      if (sign == minus) *x_int = -*x_int;
      x_fract = x;
    }
  }
  return x_fract;
}

long double s21_modfl(long double num, long double *before_point) {
  long double result = num;
  if (num != num) {
    *before_point = num;
  } else {
    int sign = s21_signbit(num);
    char *s = (char *)&num;
    if (sign) {
      num = -(num);
    }
    long long int exponent_bits = 0;
    int counter = 79;
    for (int bit = 9; bit >= 0; bit--) {
      for (int i = 0; i <= 7; i++) {
        char ff = ((1 << (7 - i)) & *(s + bit)) ? 1 : 0;
        if (counter >= 64 && counter <= 78) {
          exponent_bits = (exponent_bits << 1) + ff;
        }
        counter--;
      }
    }
    exponent_bits -= 16383;
    if (exponent_bits < 0) {
      *before_point = 0;
    } else if (exponent_bits <= 63) {
      long double num_copy = num;
      counter = 79;
      for (int bit = 9; bit >= 0; bit--) {
        for (int i = 0; i <= 7; i++) {
          char ff = ((1 << (7 - i)) & *(s + bit)) ? 1 : 0;
          if ((counter <= 63) && counter < (63 - exponent_bits)) {
            if (ff) {
              *(s + bit) ^= (1 << (7 - i));
            }
          }
          counter--;
        }
      }
      *before_point = num;
      result = num_copy - num;
    } else {
      *before_point = num;
      result = 0;
    }
    if (sign) {
      *before_point = -(s21_fabsl(*before_point));
      result = -(s21_fabsl(result));
    }
  }

  return result;
}
