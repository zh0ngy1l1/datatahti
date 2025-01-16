#include<bits/stdc++.h>
using namespace std;

const int M = INT32_MAX/2 - 1;

void solve() {
    int dp[1000001];
    for (int i = 1; i < 10; i++) dp[i] = 1;

    for (int d = 2; d <= 6; d++) {
        int x;
        for (int i = pow(10, d-1); i < pow(10, d); i++) {
            dp[i] = M;
            x = i;
            for (int _ = 0; _ < d; _++) {
                dp[i] = min(dp[i], dp[i-(x%10)]);
                x /= 10;
            }
            dp[i]++;
        }
    }

    dp[1000000] = dp[999999] + 1;
    
    int N;
    cin >> N;
    cout << dp[N] << endl;

}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}