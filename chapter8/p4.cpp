#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int s[N], a[N] = {0};
    for (int i = 0; i < N; i++) cin >> s[i];

    deque<int> d(1, 0);
    for (int i = N-1; i >= 0; i--) {
        while (!d.empty() && d.back() <= s[i]) d.pop_back();

        if (!d.empty()) a[i] = d.back();
        d.push_back(s[i]);
    }

    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}