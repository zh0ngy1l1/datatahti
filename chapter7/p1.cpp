#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N;
    cin >> N;
    int dp[N+6] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= 6; i++) {
        for (int j = 0; j < i; j++) dp[i] += dp[j];
    }

    for (int i = 7; i <= N; i++) {
        for (int j = i-6; j < i; j++) dp[i] += dp[j];
    }
    cout << dp[N] << endl;
    return;
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}