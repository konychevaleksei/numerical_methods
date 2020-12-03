#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return 3 * x + log(x);
}

double eps[] = {0.001, 0.000001, 0.000000001};

//var: 11
int main() {
  double a = 3, x, c = 0.5, d = 1e9, d1 = 0;

  for (int i = 0, j = 0; i < (1 << 16); ++i) {
    if (abs(d1 - d) < eps[j])
      j++, cout << "Значение производной: " << fixed << setprecision(9) << d << " (с погрешностью ε = " << eps[j - 1] << ") | количество итераций: " << i << endl;

    x = a + c;
    d1 = d, d = (f(x) - f(a)) / c;
    c /= 2;
  }

  cout << endl << "Значение производной в явном виде: " << 3 + 1 / a;

}