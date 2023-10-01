// https://cses.fi/problemset/task/1072 18.9.2023

#include <iostream>
using namespace std;

unsigned long long algorithm(long k)
{
    // k^2 C 2 = k^2 * (k^2 - 1)
    // cases that don't work:
    // 
    unsigned long long ksquared = k * k;
    return ksquared * (ksquared - 1) / 2 - 4 * (k - 1) * (k - 2);
}

int main()
{
    long n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        unsigned long long solution = algorithm(k);
        cout << solution << endl;
    }
}