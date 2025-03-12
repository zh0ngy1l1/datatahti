#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> huoneet, ryhmat;
    for (int _=0, a; _<n; _++) {
        cin >> a;
        huoneet.push(a);
    }
    for (int _=0, b; _<m; _++) {
        cin >> b;
        ryhmat.push(b);
    }
    int ans = 0;
    while (!ryhmat.empty() && !huoneet.empty()) {
        if (huoneet.top() >= ryhmat.top()) {
            huoneet.pop();
            ans++;
        }
        ryhmat.pop();
    }
    cout << ans << "\n";

}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve(); 
}