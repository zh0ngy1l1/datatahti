#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int n) {
    if (n == 0) return 0;
    if ((n % 2) == 0) return (__builtin_popcount(n) + f(n-1));
    else return (2 * f(n/2) + n/2 + 1);
}

void solve() {
    int n;
    cin >> n;
    cout << f(n) << "\n";
}


signed main() {
    solve();
}