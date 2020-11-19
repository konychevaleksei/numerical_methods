#include <bits/stdc++.h>
using namespace std;

double **a, *y, *x, t; //матрицы сумм, значений исходной СЛАУ и значений коэффициентов соответственно
int n, N; //степень регрессии и количество узловых значений соответственно
vector<double> X, Y; //абсциссы и ординаты узлов
vector<char> var = {'a', 'b', 'c', 'd', 'e', 'f'};

double * gauss(double **a, double *y, int n) {
  double *x, max;
  int k, index;
  const double eps = 0.00001;
  x = new double[n];
  k = 0;
  while (k < n) {
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++) {
      if (abs(a[i][k]) > max) {
        max = abs(a[i][k]);
        index = i;
      }
    }

    if (max < eps) {
      cout << "Решение получить невозможно из-за нулевого столбца ";
      cout << index << " матрицы" << endl;
      return 0;
    }

    for (int j = 0; j < n; j++)
			swap(a[index][j], a[k][j]);

		swap(y[k], y[index]);

    for (int i = k; i < n; i++) {
      double temp = a[i][k];
      if (abs(temp) < eps)
				continue;

      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] / temp;

      y[i] = y[i] / temp;

      if (i == k)
				continue;

      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];

      y[i] = y[i] - y[k];
    }
    k++;
  }

  for (k = n - 1; k >= 0; k--) {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  return x;
}

double get_sum(int pwrX, int pwrY) {
	if (pwrX == 0 && pwrY == 0)
		return (double)N;

	double res = 0;
	for (int i = 0; i < N; ++i) {
		double k = 1;
		for (int j = 0; j < pwrX; j++)
			k *= X[i];
		for (int j = 0; j < pwrY; j++)
			k *= Y[i];
		res += k;
	}
	return res;
}

int main() {
	freopen("algo/in.txt", "r", stdin);
	freopen("algo/out.txt", "w", stdout);

	cin >> N >> n; n++;
	for (int i = 0; i < N; ++i)
		cin >> t, X.push_back(t);

	for (int i = 0; i < N; ++i)
		cin >> t, Y.push_back(t);

  a = new double*[n];
  y = new double[n];

  for (int i = 0; i < n; i++) {
    a[i] = new double[n];
    for (int j = 0; j < n; j++)
      a[i][j] = get_sum(n - j - 1 + i, 0), cout << "Σ(x[i]^" << n - j - 1 + i << ") = " << a[i][j] << endl;
  }

  for (int i = 0; i < n; i++)
    y[i] = get_sum(i, 1), cout << "Σ(x[i]^" << i << " * y[i]) = " << y[i] << endl;

  x = gauss(a, y, n);

  for (int i = 0; i < n; i++)
    cout << var[i] << " = " << x[i] << endl;

  return 0;
}
