#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> prefix_xor = {0};
    int max_val=0;
    for (int i=1, x; i<n+1; i++) {
        cin >> x;
        prefix_xor.push_back(prefix_xor[i-1] ^ x);
        max_val |= x;
    }

    sort(prefix_xor.begin(), prefix_xor.end());
    prefix_xor.erase(unique(prefix_xor.begin(), prefix_xor.end()), prefix_xor.end());
    
    int max_pow = 32 - __builtin_clz(*prefix_xor.rbegin());

    unordered_set<int> smaller_nums;
    for (int i=0; prefix_xor[i]<(1<<(max_pow-1)); i++) smaller_nums.insert(prefix_xor[i]);
    vector<int> greater_nums;
    for (int i=n; prefix_xor[i]>=(1<<(max_pow-1)); i--) greater_nums.push_back(prefix_xor[i]);

    for (int d=max_val; d>0; d--) {
        for (auto i : greater_nums) if (smaller_nums.count(i ^ d)) {cout << d << endl; d=0; break;}
    }
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}