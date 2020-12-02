#include <bits/stdc++.h>
using namespace std;

double f(double x) { 
    return 3 * x * x + log(x); 
} 

double trapezoid(float a, float b, float n) { 
    double h = (b - a) / n, s = f(a) + f(b);

    for (int i = 1; i < n; ++i) 
        s += 2 * f(a + i * h); 
  
    return (h / 2) * s; 
} 

double simpson(double a, double b, int n) {
	double h, x[n + 1], sum = 0;
	int j;
	h = (b - a) / n;
	
	x[0] = a;
	
	for(j = 1; j <= n; j++)
		x[j] = a + h * j;
	
	for(j = 1; j <= n / 2; j++)
		sum += f(x[2 * j - 2]) + 4 * f(x[2 * j - 1]) + f(x[2 * j]);
	
	return sum * h / 3;
}

double rect(double x0, double xn, int n) {
    double j = (xn - x0) / (double)n, cur = j / 2 + x0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += f(cur) * j;
        cur += j;
    }
    
    return sum;
}
  
int main() {
    double x0 = 1, xn = 2; 
  
    int n = 6; 
  
    cout << trapezoid(x0, xn, n) << endl; 
    cout << simpson(x0, xn, n) << endl; 
    cout << rect(x0, xn, n) << endl; 

    return 0; 
} 