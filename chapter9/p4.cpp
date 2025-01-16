#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> st;
int M = 1;

void upd(int k, int x) {
    k += M;
    st[k] = {x, x};

    for (k /= 2; k > 0; k /= 2) {
        st[k].first = min(st[2*k].first, st[2*k + 1].first);
        st[k].second = max(st[2*k].second, st[2*k + 1].second);
    }
}

void rq(int a, int b) {
    a += M; b += M;
    int mn = st[a].first, mx = st[a].second;
    while (a <= b) {
        if (a % 2 == 1) {
            mn = min(mn, st[a].first);
            mx = max(mx, st[a++].second);
        }
        if (b % 2 == 0) {
            mn = min(mn, st[b].first);
            mx = max(mx, st[b--].second);
        }
        a/=2; b/=2;
    }
    cout << mn << " " << mx << "\n";
}

void solve() {
    int N, Q;
    cin >> N >> Q;

    while (M < N) M *= 2;
    st.resize(2*M);

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        upd(i, x);
    }

    char o;
    int a, b;
    for (int _ = 0; _ < Q; _++) {
        cin >> o >> a >> b;
        if (o == '?') rq(--a, --b);
        else upd(--a, b);
    }
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}