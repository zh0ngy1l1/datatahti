#include <bits/stdc++.h>
using namespace std;
#define int long

int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    int u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

int M = 1E9+7;
int PHI = 500000002;

void solve() {
    int n;
    cin >> n;
    for (int _=0, a, b, c; _<n;_++) {
        cin >> a >> b >> c;
        cout << modpow(a, modpow(b, c, M-1), M) << "\n";
    }    
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}