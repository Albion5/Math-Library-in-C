#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result;
  if (s21_isnan(x) || x < 0) {
    result = s21_nan;
    if (s21_signbit(x)) result = -result;
  } else if (s21_isinf(x) || x == 0) {
    result = x;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}