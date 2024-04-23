#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (s21_isnan(x) || s21_fabs(x) > 1) {
    result = s21_nan;
  } else if (x == 1) {
    result = 0;
  } else if (x == 0) {
    result = s21_PI_2;
  } else if (x == -1) {
    result = s21_PI;
  } else if (-1.0 < x && x < 0.0) {
    result = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (0.0 < x && x < 1.0) {
    result = s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return result;
}