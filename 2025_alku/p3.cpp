#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, a, b;
    cin >> m >> a >> b;
    if (a == 0 ^ b == 0) {
        cout << "NO\n";
        return;
    }
    if (a + b > m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int t = m - a - b;

    for (int i = 0; i < m; i++) {
        cout << i + 1 << " ";
    } cout << "\n";
    
    for (int i = 0; i < a+b; i++) {
        cout << (i + a) % (a+b) + 1 << " ";
    }
    for (int i = a+b; i < m; i++) {
        cout << i + 1 << " ";
    } cout << "\n";
}

int main() {
	int n;
	cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
    
}
	
