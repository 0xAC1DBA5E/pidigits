#include <cmath>
#include <iostream>

using INT = int64_t;
using FLOAT = double;

// 16^n mod c, O(log(n))
FLOAT expmod16(FLOAT n, FLOAT c) {
  FLOAT r = 1.0;
  // set t to largest power of 2 <= n
  INT t = n ? (INT)1 << (31 - __builtin_clz((INT)n)) : (INT)1;
  for (;;) {
    if (n >= t) {
      r = 16.0 * r;
      r -= (INT)(r / c) * c;
      n -= t;
    }
    t >>= 1;
    if (t < 1)
      break;
    r = r * r;
    r -= (INT)(r / c) * c;
  }
  return r;
}

INT pi16(INT n) {
  FLOAT s1 = 0.0, s2 = 0.0, s3 = 0.0, s4 = 0.0, _n = n;
// part 1
#pragma omp parallel for
  for (INT k = 0; k < n; ++k) {
    FLOAT p = 8.0 * k, e = _n - (FLOAT)k;
    FLOAT p1 = p + 1, p2 = p + 4, p3 = p + 5, p4 = p + 6;
#pragma omp atomic
    s1 += expmod16(e, p1) / p1;
#pragma omp atomic
    s2 += expmod16(e, p2) / p2;
#pragma omp atomic
    s3 += expmod16(e, p3) / p3;
#pragma omp atomic
    s4 += expmod16(e, p4) / p4;
#pragma omp atomic
    s1 -= (INT)s1;
#pragma omp atomic
    s2 -= (INT)s2;
#pragma omp atomic
    s3 -= (INT)s3;
#pragma omp atomic
    s4 -= (INT)s4;
  }
  // part 2
  static constexpr INT N = 100;
  for (INT k = n; k <= n + N; ++k) {
    FLOAT p = 8.0 * k, e = _n - (FLOAT)k;
    FLOAT p1 = p + 1, p2 = p + 4, p3 = p + 5, p4 = p + 6;
    FLOAT pn = std::pow(16.0, e);
    if (pn / p < 1e-17)
      break;
    s1 += pn / p1;
    s2 += pn / p2;
    s3 += pn / p3;
    s4 += pn / p4;
    s1 -= (INT)s1;
    s2 -= (INT)s2;
    s3 -= (INT)s3;
    s4 -= (INT)s4;
  }
  FLOAT s = 4 * s1 - 2 * s2 - s3 - s4;
  s = s - (INT)s + 1.0;
  s = std::fabs(s);
  return std::pow(16.0, 8.0) * (s - std::floor(s));
}
