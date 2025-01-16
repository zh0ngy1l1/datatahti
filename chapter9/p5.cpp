#include <bits/stdc++.h>
using namespace std;

vector<int> st;
int M = 1;

void upd(int k, int x) {
    k += M;

    st[k] = x;
    for (k/=2; k>0; k/=2) st[k] = st[2*k] + st[2*k+1];
}

void upd2(int a, int b) {
    upd(a, st[a+M] + 1);
    upd(b + 1, st[b+1+M] - 1);
}

int rq(int a, int b) {
    a += M; b += M;
    int s = 0;
    
    while (a <= b) {
        if (a % 2 == 1) s += st[a++];
        if (b % 2 == 0) s += st[b--];
        a/=2; b/=2;
    }
    return s;
}

void solve() {
    int N, Q;
    cin >> N >> Q;

    while (M < N) M *= 2;
    st.resize(2*M);

    int p, c;
    cin >> p;
    upd(0, p);
    for (int i = 1; i < N; i++) {
        cin >> c;
        upd(i, c-p);
        p = c;
    }

    char o;
    int a, b;
    for (int _ = 0; _ < Q; _++) {
        cin >> o;
        if (o == '?') {
            cin >> a;
            cout << rq(0, a-1) << "\n";
        } else {
            cin >> a >> b;
            upd2(a-1, b-1);
        }
    }
}

int main() {
    solve();
}