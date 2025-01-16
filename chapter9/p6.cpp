#include <bits/stdc++.h>
using namespace std;

vector<int> st;
int S = 1;

void upd(int k, int x) {
    k += S;
    st[k] = x;
    for (k/=2; k>0; k/=2) st[k] = max(st[2*k], st[2*k + 1]);
}

int search(int r) {
    int i = 1;
    if (st[i]<r) return 0;
    while (i<S) {
        if (st[2*i] >= r) i = 2*i;
        else i = 2*i + 1;
    }
    upd(i-S, st[i] - r);
    return i-S+1;
}

void solve() {
    int N, M;
    cin >> N >> M;

    while (S < N) S *= 2;
    st.resize(2*S);

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        upd(i, x);
    }
    for (int _ = 0, x; _ < M; _++) {
        cin >> x;
        cout << search(x) << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}