#include "s21_math.h"

long double s21_atan(double x) {
  sign sign_x = s21_signbit(x);
  long double result;
  if (s21_isnan(x)) {
    result = s21_nan;
    if (sign_x) result = -result;
  } else if (x == 0) {
    result = x;
  } else if (s21_isinf(x)) {
    result = s21_PI_2;
    if (sign_x) result = -result;
  } else if (s21_fabs(x) > 0.99999 && s21_fabs(x) < 1.00001) {
    result = s21_ATAN_1;
    if (sign_x) result = -result;
  } else {
    long double x_dbl = (long double)x;
    if (s21_fabs(x) > 1) x_dbl = 1 / x_dbl;
    long double term = x_dbl;
    result = x_dbl;
    long double result_prev = 0;
    unsigned step = 1;
    while (result - result_prev) {
      result_prev = result;
      term *= -1.0L * (x_dbl * x_dbl);
      step += 2;
      result += term / step;
    }
    if (s21_fabs(x) > 1) result = -result + (sign_x ? -s21_PI_2 : s21_PI_2);
  }
  return result;
}