#include <bits/stdc++.h>
using namespace std;
#define int long

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> loc;
    int prev = 0;
    loc[0] = 1;

    for (int i=1, in; i<=n; i++) {
        cin >> in;
        prev = (prev + in)%n;
        if (loc.count(prev)) {
            cout << loc[prev] << " " << i << "\n";
            break;
        }
        loc[prev] = i+1;
    }
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve(); 
}