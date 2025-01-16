#include <bits/stdc++.h>
#define M 1000000007
 
using namespace std;
 
const int N = 100100;
 
int v[N];
 
int calc(int l1, int r1, int l2, int r2, int f) {
    if (l1 == r1 && l2 == r2) return 0;
    
    if (f == 0) {
        if (l1 < r1 && l2 < r2) return v[l1] ^ v[l2];
        else return 0;
    }
    
    if (l1 == r1) return calc(l2, r2, l2, r2, f);
    if (l2 == r2) return calc(l1, r1, l1, r1, f);
    
    if (l1 == l2) {
        int m1 = l1;
        while (m1 < r1 && (v[m1]&f) == 0) ++m1;
        return calc(l1, m1, m1, r1, f/2);
    }
    
    int m1 = l1, m2 = l2;
    while (m1 < r1 && (v[m1]&f) == 0) ++m1;
    while (m2 < r2 && (v[m2]&f) == 0) ++m2;
    
    int r = 0;
    if (l1 < m1 && m2 < r2) r = max(r, calc(l1, m1, m2, r2, f/2));
    if (m1 < r1 && l2 < m2) r = max(r, calc(m1, r1, l2, m2, f/2));
    
    if (r == 0) r = max(calc(l1, m1, l2, m2, f/2), calc(m1, r1, m2, r2, f/2));
    return r;
}
 
void solve() {
    int n;
    cin >> n;
    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] ^= v[i-1];
    }
    
    sort(v, v+n+1);
    
    cout << calc(0, n+1, 0, n+1, 1<<30) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    solve();
    
    return 0;
}