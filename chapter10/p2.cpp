#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    int prefix_xors[N+1] = {0};
    for (int i = 1; i <= N; i++) {
        cin >> prefix_xors[i];
        prefix_xors[i] ^= prefix_xors[i-1];
    } 
    
    int a, b;
    for (int _ = 0; _ < Q; _++) {
        cin >> a >> b;
        cout << (prefix_xors[a-1] ^ prefix_xors[b]) << "\n";
    }
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}