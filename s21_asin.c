#include "s21_math.h"

long double s21_asin(double x) {
  long double result;
  if (s21_isnan(x) || s21_fabs(x) > 1) {
    result = s21_nan;
  } else if (x == 0) {
    result = x;
  } else {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return result;
}