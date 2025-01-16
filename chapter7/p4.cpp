#include <bits/stdc++.h>
using namespace std;

void solve() {
    string A, B;
    cin >> A >> B;
    int a = A.size(), b = B.size();
    int dp[a+1][b+1];

    dp[0][0] = 0;
    for (int i = 1; i <= a; i++) dp[i][0] = i;
    for (int i = 1; i <= b; i++) dp[0][i] = i;

    for (int x = 1; x <= a; x++) for (int y = 1; y <= b; y++) {
        dp[x][y] = min(
            min(dp[x][y-1] + 1, dp[x-1][y] + 1),
            dp[x-1][y-1] + ((A[x-1] == B[y-1]) ? 0 : 1)
        );
    }
    cout << dp[a][b] << endl;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}