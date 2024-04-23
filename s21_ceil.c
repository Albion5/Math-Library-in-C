#include "s21_math.h"

long double s21_ceil(double x) {
  double result;
  if (s21_isnan(x) || s21_isinf(x) || x == 0) {
    result = x;
  } else {
    x = s21_modf(x, &result);
    if (x > 0) result++;
  }
  return (long double)result;
}
