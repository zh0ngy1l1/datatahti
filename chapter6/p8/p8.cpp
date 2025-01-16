#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;

    multiset<int> k;
    for (int _=0; _<K; _++) k.insert(0);

    vector<pair<int, int>> s;
    for (int _=0, e, b; _<N; _++) {
        cin >> b >> e;
        s.push_back({e, b});
    }

    sort(s.begin(), s.end());

    // for(auto i:s) cout << i.first << " " << i.second << "; ";
    // cout << endl;
    
    int a = 0, e, b;
    for (pair<int, int> p : s) {
        e = p.first; b = p.second;
        auto it = k.lower_bound(b);
        if (it == k.begin()) continue;
        it--;
        k.erase(it);
        k.insert(e);
        a++;
    }

    cout << a << "\n";
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);

    solve();
}