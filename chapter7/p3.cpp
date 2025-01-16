#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N, M;
    cin >> N >> M;
    int grid[N+1][M+1] = {};
    grid[1][0] = 1;
    char x;

    for (int r = 1; r <= N; r++) for (int c = 1; c <= M; c++) {
        cin >> x;
        if (x == '*') continue;
        grid[r][c] = (grid[r-1][c] + grid[r][c-1]) % MOD;
    }

    cout << grid[N][M] << endl;

}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);

    solve();
}