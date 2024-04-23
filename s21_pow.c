#include "s21_math.h"

int isint(double x) {
  double tmp;
  s21_modf(x, &tmp);
  return x == tmp;
}

int iseven(double x) { return isint(x) && s21_fmod(x, 2) == 0; }

int isodd(double x) { return isint(x) && s21_fmod(x, 2) != 0; }

long double s21_pow(double base, double exp) {
  sign sign_base = s21_signbit(base), sign_exp = s21_signbit(exp);
  long double result = 0;
  if (base == 1 || exp == 0) {
    result = 1;
  } else if (s21_isnan(base) || s21_isnan(exp)) {
    result = s21_nan;
  } else if (base == 0) {
    if (sign_exp && !s21_isinf(exp) && (iseven(exp) || !isint(exp))) {
      result = s21_inf;
    } else if (sign_exp && s21_isinf(exp)) {
      result = s21_inf;
    } else if (!sign_exp && (!isint(exp) || iseven(exp))) {
      result = 0;
    } else if (isodd(exp)) {
      if (sign_exp) result = s21_inf;
      if (!sign_exp) result = 0;
      if (sign_base) result = -result;
    }
  } else if (s21_isinf(exp)) {
    if (base == -1) {
      result = 1;
    } else if (sign_exp) {
      result = s21_fabs(base) < 1 ? s21_inf : 0;
    } else {
      result = s21_fabs(base) < 1 ? 0 : s21_inf;
    }
  } else if (s21_isinf(base)) {
    if (sign_base) {
      if (sign_exp && isodd(exp)) result = -(0.0);
      if (sign_exp && (!isint(exp) || iseven(exp))) result = 0;
      if (!sign_exp && isodd(exp)) result = -s21_inf;
      if (!sign_exp && (!isint(exp) || iseven(exp))) result = s21_inf;
    } else {
      if (sign_exp) result = 0;
      if (!sign_exp) result = s21_inf;
    }
  } else if (sign_base && !s21_isinf(base) && !s21_isinf(exp) && !isint(exp)) {
    result = -s21_nan;
  } else {
    if (sign_base) base = -base;
    result = s21_exp(exp * s21_log(base));
    if (sign_base && isodd(exp)) result = -result;
  }
  return result;
}
