#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    
    int s[N];
    for (int i = 0; i < N; i++) cin >> s[i];

    pair<int, int> best[1<<N];
    pair<int, int> alt;

    best[0] = {1, 0};

    for (int k = 1; k < (1<<N); k++) {
        best[k] = {N, 0};

        for (int x = 0; x < N; x++) if (k & (1 << x)) {
            alt = best[k ^ (1 << x)];
            if (alt.second + s[x] > K) {
                alt.first++;
                alt.second = s[x];
            } else alt.second += s[x];

            best[k] = min(best[k], alt);
        }
    }

    cout << best[(1 << N) - 1].first << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}