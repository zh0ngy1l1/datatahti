#include<bits/stdc++.h>
using namespace std;

int N;
void solve() {
    vector<char> C;
    string S, o;
    cin >> S;
    sort(S.begin(), S.end());
    int x=0;
    do {x++;
        o.append("\n" + S);
    } while (next_permutation(S.begin(), S.end()));
    cout << x << o;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}