#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX/2-1
#define int long long

void solve() {
    int N, S=0, m=INF;
    cin >> N;
    int o[N];
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        o[i]=x;
        S+=x;
    }
 
    for (int b = 0; b < (1<<N); b++) {
        int s = 0;
        for (int c = 0; c < N; c++) {
            if (1<<c & b) s+= o[c];
        }
        m=min(m, abs(S-2*s));
    }
    cout << m << "\n";
}
 
signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}