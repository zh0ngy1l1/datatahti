#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long



signed main() {
    int n, m;
    cin >> n;
    vector<pair<int, int>> s;
    for (int i=0; i<n; i++) {
        cin >> m;
        s.push_back({m, i});
    }
    sort(s.rbegin(), s.rend());
    // for (auto i : s) cout << i.first << ", " << i.second << "\n";
    
    m = n;
    for (pair<int, int> p : s) {
        if (m < p.second) break;
        m = p.second;
        n--;
    }
    cout << n<< endl;
}