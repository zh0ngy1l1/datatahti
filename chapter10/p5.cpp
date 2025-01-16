#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    map<char, int> M;
    M['A']=0;M['C']=1;M['G']=2;M['T']=3; 

    int N;
    cin >> N;

    int s[N];
    string t;
    for (int i=0; i<N; i++) {
        cin >> t;
        s[i] = (M[*t.begin()]<<2) + M[*t.rbegin()];
    }
    
    int ways[1<<N][4] = {0};
    for (int c=0; c<4; c++) ways[0][c] = 1;

    for (int a=1; a<(1<<N); a++) {
        for (int k=0; k<N; k++) if ((a & (1<<k))) {
            ways[a][s[k]&3] += ways[a ^ (1<<k)][s[k]>>2];
        }
    }

    cout << ways[(1<<N)-1][0]+ways[(1<<N)-1][1]+ways[(1<<N)-1][2]+ways[(1<<N)-1][3] << "\n";
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}