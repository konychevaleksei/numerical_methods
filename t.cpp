#include <iostream>
#include <iomanip>
using namespace std;

//BISECTION

#define EP 0.001

double f(double x) {
    return tan(0.5 * x + 0.1) - x * x;
}

void bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "The section is incorrect\n";
        return;
    }
    double c = a;
    int it = 0;
    while ((b - a) >= EP) {
        it++;
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << fixed << setprecision(3) << "Equation root with accuracy of 1e-3 : " << c << ", number of iterations: " << it;
}

int main() {
    double a = -0.2, b = -0.1;
    bisection(a, b);
    return 0;
}


//newton
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int it = 0;

double f(double x) {
    return tan(0.5 * x + 0.1) - x * x;
}

double FindRoot(double (*f)(double), double x0) {
    double x = x0, df, EP = 0.000001;
    df = (f(x + EP) - f(x)) / EP;
        
        
    while (fabs(floor(x * 1e5) / 1e5 - x) < EP)
        x = x - f(x) / df, it++;
        
    return x;
}

int main() {
    double x0, x;
    cin >> x;

    x = FindRoot(f, x);
    cout << "Equation root x = " << fixed << setprecision(6) << x << ", number of iterations: " << it << endl;
    return 0;
}


//chord
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define EP 0.000000001
int it = 0;
 
double f(double x) {
    return tan(0.5 * x + 0.1) - x * x;
}
 
double find(double ifm, double sup) {
    while (fabs(sup - ifm) > EP) {
        ifm = sup - (sup - ifm) * f(sup) / (f(sup) - f(ifm));
        sup = ifm - (ifm - sup) * f(ifm) / (f(ifm) - f(sup));
        it++;
    }
 
    return sup;
}
 
int main() {
    double a = -0.2, b = -0.1;
    cout << "Equation root x = " << fixed << setprecision(9) << find(a, b) << ", number of iterations: " << it << endl;
    return 0;
}




