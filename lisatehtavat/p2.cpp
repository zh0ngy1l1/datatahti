#include <bits/stdc++.h>
using namespace std;
#define int long

void solve() {
    int n;
    cin >> n;
    multiset<int> pf;
    int prev = 0;
    pf.insert(0);
    for (int i=0, a; i<n; i++) {
        cin >> a;
        prev += a;
        pf.insert(prev);
    }
    int ans = 0, a;
    
    while (!pf.empty()) {
        a = *pf.begin();
        ans += (pf.count(a)*pf.count(a) - pf.count(a))/2;
        pf.erase(a);
    }
    

    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve(); 
}