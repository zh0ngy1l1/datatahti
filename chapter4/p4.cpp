#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, M;
    multiset<int> l; //liput
    queue<int> t; // tarjoukset
    
    int x;
    cin >> N >> M;
    for (int _ = 0; _ < N; _++) {
        cin >> x;
        l.insert(x);
    }
    for (int _ = 0; _ < M; _++) {
        cin >> x;
        auto it = l.upper_bound(x);
        if (it == l.begin()) {
            cout << "QAQ\n";
            continue;
        } else {
            cout << *--it << "\n";
            l.erase(it);
        }
    }
    

}