#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, N;
    cin >> X >> N;
 
    set<int> S; // starting locations
    multiset<int> d; // distances
 
    S.insert({0, X});
    d.insert(X);
 
    int x, p, n;
 
    for (int _ = 0; _ < N; _++) {
        cin >> x;
        auto it = S.upper_bound(x);
        n = *it--;
        p = *it;
 
        S.insert(x);
 
        d.erase(d.find(n-p));
        d.insert(x-p);
        d.insert(n-x);
 
        cout << *--d.end()<< " ";
    }
    cout << endl;
 
}