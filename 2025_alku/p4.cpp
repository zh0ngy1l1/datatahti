#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<vector<long long>> computeBinomialCoefficients(long long n) {
    vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));
    
    for (long long i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1; // Base cases
        for (long long j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    return C;
}

vector<vector<long long>> computeTriangle(long long n) {
    vector<vector<long long>> T(n + 1, vector<long long>(n + 1, 0));
    T[2][1] = 1;
    for (long long i = 3; i <= n; i++) {
        T[i][1] = T[i][i-1] = 1; // Base cases
        for (long long j = 2; j < i - 1; j++) {
            T[i][j] = (j*T[i-1][j] + (i-j)*T[i-1][j-1] + (i-1)*T[i-2][j-1]) % MOD;
        }
    }
    return T;
}

vector<long long> computeFactorials(long long n) {
    vector<long long> F(n+1, 1);
    for (long long i = 1; i <= n; i++) {
        F[i] = (i*F[i-1]) % MOD;
    }
    return F;
}

vector<vector<long long>> C = computeBinomialCoefficients(2000);
vector<long long> F = computeFactorials(2000);
vector<vector<long long>> T = computeTriangle(2000);

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    // edge cases
    if ((a == 0) ^ (b == 0)) {
        cout << 0 << endl;
        return;
    }
    if (a + b > n) {
        cout << 0 << endl;
        return;
    }
    if (a == 0 && b == 0) {
        cout << F[n] << endl;
        return;
    }

    long long m = a+b;

    long long coeff = C[n][m] * F[n] % MOD;

    cout << (T[m][a] * coeff) % MOD<< endl;
    return;
}

int main() {
    int n;
	cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
}
