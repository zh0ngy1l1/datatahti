#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INT32_MAX/2-1

void solve() {
    int N;
    cin >> N;
    ll s[N], lsi[N];
    for (int i = 0; i < N; i++) cin >> s[i];

    deque<pair<int, int>> d(1, {INF, 0});
    for (int i = 0; i < N; i++) {
        while (!d.empty() && d.back().first >= s[i]) d.pop_back();

        if (!d.empty()) lsi[i] = d.back().second;
        else (lsi[i] = -1);

        d.push_back({s[i], i});
    }

    d.clear();
    d.push_back({INF, 0});

    ll m = 0;
    for (int i = N-1; i >= 0; i--) {
        while (!d.empty() && d.back().first >= s[i]) d.pop_back();

        if (!d.empty()) m = max(m, s[i]*(d.back().second-lsi[i]-1));
        else m = max(m, s[i]*(N-lsi[i]-1));

        d.push_back({s[i], i});
    }

    cout << m << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}