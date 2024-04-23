#include "s21_math.h"

long double s21_fabsl(long double x) { return s21_signbit(x) ? -x : x; }

long double s21_fabs(double x) { return s21_fabsl(x); }