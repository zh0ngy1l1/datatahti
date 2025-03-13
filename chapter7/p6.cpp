#include <bits/stdc++.h>
using namespace std;
#define int long long

const int num_points = 1200;

// Function to compute the cosine product for a given x
double cosine_product(int n, double x) {
    double product = 1.0;
    for (int k = 1; k <= n; ++k) {
        product *= cos(k * x);
    }
    return product;
}

// Function to compute the integral using the trapezoidal rule
double compute_integral(int n) {
    double a = 0.0, b = 2 * M_PI; // Integration limits
    double h = (b - a) / num_points; // Step size
    double integral = 0.0;

    for (int i = 0; i <= num_points; ++i) {
        double x = a + i * h;
        double weight = (i == 0 || i == num_points) ? 0.5 : 1.0; // Trapezoidal weights
        integral += weight * cosine_product(n, x);
    }

    integral *= h; // Scale by step size
    return integral;
}

// Function to compute a(n)
int a(int n) {
    // Check if 4 divides n(n + 1)
    if ((n * (n + 1)) % 4 != 0) {
        return 0.0;
    }

    // Compute the integral
    double integral = compute_integral(n);

    // Calculate and return the result
    return round(((1LL << (n-2)) / M_PI) * integral);
}

signed main() {
    int n;
    cin >> n;
    cout << a(n) << endl;
    return 0;
}