#include "s21_math.h"

long double s21_cos(double x) {
  sign sign_x = s21_signbit(x);
  long double result;
  if (s21_isnan(x) || s21_isinf(x)) {
    result = s21_nan;
    if (sign_x || s21_isinf(x)) result = -result;
  } else if (x == 0) {
    result = 1.0L;
  } else {
    long double x_ldbl = s21_fmod(x, s21_PI * 2.0L);
    long double term = 1;
    result = 1;
    long double result_prev = 0;
    unsigned step = 0;
    while (result - result_prev) {
      result_prev = result;
      term *= -1.0L * (x_ldbl * x_ldbl);
      step += 2;
      result += term / s21_factorial(step);
    }
  }
  return result;
}