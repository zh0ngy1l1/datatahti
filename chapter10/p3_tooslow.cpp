#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve() {
    int N;
    cin >> N;
    int s = 0;
    for (int i = 1; i <= N; i++) {
        s += __builtin_popcount(i);
    }
    cout << s << "\n";
}
 
 
signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}