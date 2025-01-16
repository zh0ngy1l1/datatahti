#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, x;
    unordered_set<int> s;
    queue<int> q;
    
    cin >> N;

    int f;
    int m = 0, d = 0;
    for (int _ = 0; _ < N; _++) {
        cin >> x;

        if (s.count(x)) {
            do {
                f = q.front();
                s.erase(f);
                q.pop();
                d--;
            } while (f != x);
        }
        q.push(x);
        s.insert(x);
        d++;

        m = max(m, d);
    }
    cout << m << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}