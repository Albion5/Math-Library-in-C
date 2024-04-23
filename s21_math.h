#ifndef C4_S21_MATH_S21_MATH_H_
#define C4_S21_MATH_S21_MATH_H_

#define s21_nan (__builtin_nanl(""))
#define s21_isnan(x) (__builtin_isnan(x))

#define s21_inf (__builtin_infl())
#define s21_isinf(x) (__builtin_isinf(x))

#define s21_signbit(x) (__builtin_signbit(x))

#define s21_E 2.718281828459045235360287471352662498L        /* e */
#define s21_LOG2E 1.442695040888963407359924681001892137L    /* log_2 e */
#define s21_LOG10E 0.434294481903251827651128918916605082L   /* log_10 e */
#define s21_LN2 0.693147180559945309417232121458176568L      /* log_e 2 */
#define s21_LN10 2.302585092994045684017991454684364208L     /* log_e 10 */
#define s21_PI 3.141592653589793238462643383279502884L       /* pi */
#define s21_PI_2 1.570796326794896619231321691639751442L     /* pi/2 */
#define s21_PI_4 0.785398163397448309615660845819875721L     /* pi/4 */
#define s21_1_PI 0.318309886183790671537767526745028724L     /* 1/pi */
#define s21_2_PI 0.636619772367581343075535053490057448L     /* 2/pi */
#define s21_2_SQRTPI 1.128379167095512573896158903121545172L /* 2/sqrt(pi) */
#define s21_SQRT2 1.414213562373095048801688724209698079L    /* sqrt(2) */
#define s21_SQRT1_2 0.707106781186547524400844362104849039L  /* 1/sqrt(2) */
#define s21_ATAN_1 0.785398163397448309628202239851546551L   /* atan(1) */
// #define s21_TAN_PI_2 16331239353195370.0L

typedef enum sign { plus, minus } sign;

int s21_abs(int x);
// computes absolute value of an integer value

long double s21_acos(double x);
// computes arc cosine

long double s21_asin(double x);
// computes arc sine

long double s21_atan(double x);
// computes arc tangent

long double s21_ceil(double x);
// returns the nearest integer not less than the given value

long double s21_cos(double x);
// computes cosine

long double s21_exp(double x);
// returns e raised to the given power

long double s21_fabs(double x);
// computes absolute value of a floating-point value

long double s21_floor(double x);
// returns the nearest integer not greater than the given value

long double s21_fmod(double x, double y);
// remainder of the floating-point division operation

long double s21_log(double x);
// computes natural logarithm

long double s21_pow(double base, double exp);
// raises a number to the given power

long double s21_sin(double x);
// computes sine

long double s21_sqrt(double x);
// computes square root

long double s21_tan(double x);
// computes tangent

/*additional auxiliary*/
double s21_modf(double x, double *x_int);
// long double s21_modfl(long double x, long double* x_int);
// breaks a number into integer and fractional parts

double s21_frexp10(double arg, int *exp);
// decomposes a number into significand and a power of 10

double s21_frexp(double arg, int *exp);
// decomposes a number into significand and a power of 2

long double s21_factorial(unsigned x);
long double s21_fabsl(long double x);
int s21_isinfl(long double num);
long double s21_modfl(long double num, long double *before_point);
int is_evenl(long double num);

#endif  // C4_S21_MATH_S21_MATH_H_