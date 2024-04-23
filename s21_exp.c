#include "s21_math.h"

long double s21_exp(double x) {
  sign sign_x = s21_signbit(x);
  long double result;
  if (s21_isnan(x)) {
    result = s21_nan;
  } else if (x == 0) {
    result = 1;
  } else if (x == 1) {
    result = s21_E;
  } else if (x == -1) {
    result = 1 / s21_E;
  } else if (s21_isinf(x)) {
    if (sign_x) {
      result = +0;
    } else {
      result = s21_inf;
    }
  } else {
    long double x_ldbl = (long double)x;
    if (sign_x) x_ldbl = -x_ldbl;
    int step = 1;
    long double term = 1;
    result = 1;
    long double result_prev = 0;
    while (result - result_prev && !s21_isinfl(result)) {
      result_prev = result;
      term *= (x_ldbl / step++);
      result += term;
    }
    if (sign_x) result = 1.0L / result;
  }
  return result;
}