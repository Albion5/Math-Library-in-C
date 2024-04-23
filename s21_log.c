#include "s21_math.h"

long double s21_log(double x) {
  long double result;
  if (s21_isnan(x) || x < 0) {
    result = s21_nan;
  } else if (x == 0) {
    result = -s21_inf;
  } else if (s21_isinf(x)) {
    result = s21_inf;
  } else if (x == 1) {
    result = 0;
  } else {
    int exponent = 0;
    x = s21_frexp(x, &exponent);
    long double x_ldbl = (long double)x;
    long double z_ldbl = (x_ldbl - 1.0L) / (x_ldbl + 1.0L);
    int step = 1;
    long double term = z_ldbl;
    result = z_ldbl;
    long double result_prev = 0;
    while (result - result_prev && !s21_isinfl(result)) {
      result_prev = result;
      term *= (z_ldbl * z_ldbl);
      step += 2;
      result += (term / step);
    }
    result *= 2.0L;
    result += exponent * s21_LN2;
  }
  return result;
}