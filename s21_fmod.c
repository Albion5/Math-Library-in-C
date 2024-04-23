#include "s21_math.h"

long double s21_fmod(double x, double y) {
  sign sign_x = s21_signbit(x);
  sign sign_y = s21_signbit(x);
  long double result;
  if (s21_isnan(x) || s21_isnan(y) || s21_isinf(x) || y == 0) {
    result = s21_nan;
  } else if (x == 0) {
    result = 0;
  } else if (s21_isinf(y)) {
    result = s21_fabs(x);
  } else {
    x = sign_x ? -x : x;
    y = sign_y ? -y : y;
    double quotient = x / y;
    double quotient_int;
    s21_modf(quotient, &quotient_int);
    result = x - y * quotient_int;
  }
  return sign_x ? -result : result;
}