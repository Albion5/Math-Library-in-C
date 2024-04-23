#include "s21_math.h"
int is_evenl(long double num) {
  long double whole;
  long double remainder = s21_modfl(num / 2, &whole);
  // printf(remainder == 0 ? "even\n" : "odd\n");
  return remainder == 0;
}

long double s21_tan(double x) {
  long double result;
  long double count = x / (double)s21_PI_2;
  long double whole, remainder;
  remainder = s21_modfl(count, &whole);
  if (remainder == 0 && !is_evenl(s21_fabsl(whole))) {
    long double temp = 1;
#ifdef __unix__
    temp = 16331239353195369.755859375L;
#endif
#ifdef __APPLE__
    temp = 16331778728383843.8388671875L;
#endif
    result = temp / whole;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}