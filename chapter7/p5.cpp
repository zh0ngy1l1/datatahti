#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;
    int H[N], S[N], a;

    
    for (int i = 0; i < N; i++) {
        cin >> a;
        H[i] = a;
    }
    for (int i = 0; i < N; i++) {
        cin >> a;
        S[i] = a;
    }

    a = 0;
    int dp[X + 1] = {}; // dp[i] says the max. # pages when the sum = i

    for (int i = 0; i < N; i++) {
        for (int x = X; x >= 0; x--) {
            if ((dp[x] > 0 || x == 0) && (x+H[i] <= X)) {
                dp[x+H[i]] = max(dp[x+H[i]], dp[x] + S[i]);
            }
        }
    }
    for (auto i : dp) a = max(a, i);

    cout << a << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}