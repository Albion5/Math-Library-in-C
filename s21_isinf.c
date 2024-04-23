#include "s21_math.h"

int s21_isinfl(long double num) {
  int sign = s21_signbit(num);
  char *s = (char *)&num;
  if (sign) {
    num = -(num);
  }
  long long int exponent_bits = 0;
  unsigned long long int mantissa_bits = 0;
  int counter = 79;
  for (int bit = 9; bit >= 0; bit--) {
    for (int i = 0; i <= 7; i++) {
      char ff = ((1 << (7 - i)) & *(s + bit)) ? 1 : 0;
      if (counter >= 64 && counter <= 78) {
        exponent_bits = (exponent_bits << 1) + ff;
      } else if (counter <= 65) {
        mantissa_bits = (mantissa_bits << 1) + ff;
      }
      counter--;
    }
  }
  return (exponent_bits == 32767LL) &&
         (mantissa_bits == 9223372036854775808LLU);
}
