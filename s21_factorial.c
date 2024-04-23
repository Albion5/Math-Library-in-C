#include "s21_math.h"

long double s21_factorial(unsigned x) {
  long double fact = 1;
  for (unsigned i = 2; i <= x; i++) {
    fact *= i;
  }
  return fact;
}
