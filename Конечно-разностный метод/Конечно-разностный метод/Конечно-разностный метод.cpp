#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;



double P(double x) { return -(x * x); }

double Q(double x) { return x * x * x; }

double R(double x) { return -(x * x * (x - 9) + 3 * x * x - 9 + 6 * x); }

double A(double h, double x) { return (1 + h / 2 * P(x)) / 2; }

double B(double h, double x) { return (1 - h / 2 * P(x)) / 2; }

double C(double h, double x) { return 1 + h * h / 2 * Q(x); }

double F(double h, double x) { return h * h / 2 * R(x); }

/*void Progon(int n)
{

    double h = 10 / n;
    double alpha[n + 1], beta[n + 1];
    alpha[0] = 0;
    beta[0] = 0;
    for (int i = 0; i < n; i++)
    {
        alpha[i + 1] = B(h, i * h) / (C(h, i * h) - A(h, i * h) * alpha[i]);
        beta[i + 1] = (F(h, i * h) + A(h, i * h) * beta[i]) / (C(h, i * h) - A(h, i * h) * alpha[i]);
    }
    double y[n + 1];
    y[0] = 0;
    y[n + 1] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        y[i] = alpha[i + 1] * y[i + 1] + beta[i + 1];
    }
    cout << "x_k | y(x_k)" << endl;
    for (int i = 0; i <= n; i++)
        cout << i * h << " | " << y[i] << endl;
}
*/
int main()
{

    const int n = 10;
    double h = 0.1;
    double alpha[n + 1], beta[n + 1];
    alpha[0] = 0;
    beta[0] = 0;
    for (int i = 0; i < n; i++)
    {
        alpha[i + 1] = B(h, i * h) / (C(h, i * h) - A(h, i * h) * alpha[i]);
        beta[i + 1] = (F(h, i * h) + A(h, i * h) * beta[i]) / (C(h, i * h) - A(h, i * h) * alpha[i]);
    }
    double y[n + 1];
    y[0] = 0;
    y[n+1] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        y[i] = alpha[i + 1] * y[i + 1] + beta[i + 1];
    }
    cout << "x_k | y(x_k)" << endl;
    for (int i = 0; i <= n; i++)
        cout << i * h << " | " << y[i] << endl;
    return 0;
}