#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> prefix_xor = {0};
    for (int i=1, x; i<n+1; i++) {
        cin >> x;
        prefix_xor.push_back(prefix_xor[i-1] ^ x);
    }

    sort(prefix_xor.begin(), prefix_xor.end());
    prefix_xor.erase(unique(prefix_xor.begin(), prefix_xor.end()), prefix_xor.end());
    
    int max_pow = 32 - __builtin_clz(*prefix_xor.rbegin());
    int a=0, b=prefix_xor.size()-1;
    int ans = 0;
    while (a<b) {
        cout << a << " " << b << " " << (prefix_xor[a]^prefix_xor[b]) << endl;
        ans = max(ans, prefix_xor[a]^prefix_xor[b]);
        if ((((1 << max_pow)-1) ^ prefix_xor[b]) > prefix_xor[a]) a++;
        else b--;
    }

    cout << ans << endl;


    for (auto i : prefix_xor) cout << i << " ";
    cout << endl;


}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}