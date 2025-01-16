#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> st;
int N, M;

int mq(int a, int b) {
    a += M; b += M;
    
    int m = st[a];
    while (a <= b) {
        if (a%2==1) m = max(m, st[a++]);
        if (b%2==0) m = max(m, st[b--]);

        a /= 2; b /= 2;
    }
    return m;
}

void upd(int k, int x) {
    k += M;
    st[k] = x;
    for (k /= 2; k > 0; k /= 2) st[k] = max(st[2*k], st[2*k+1]);
}

void solve() {
    int a, b, p;
    cin >> N;

    vector<tuple<int, int, int>> v;
    vector<int> cvec;
    unordered_map<int, int> cmap;


    for (int _ = 0; _ < N; _++) {
        cin >> a >> b >> p;
        v.push_back({b, a, p});
        
        cvec.push_back(a); cvec.push_back(b);
    }

    sort(cvec.begin(), cvec.end());
    cvec.erase(unique(cvec.begin(), cvec.end()), cvec.end());
    
    int n = cvec.size();
    for (int i = 0; i < n; i++) {
        cmap[cvec[i]] = i;
    }

    M = 1;
    while (M < n) M *= 2;
    st.resize(M*2);

    sort(v.begin(), v.end());

    for (auto t : v) {
        b = cmap[get<0>(t)];
        a = cmap[get<1>(t)];
        p = get<2>(t) + (a == 0 ? 0 : mq(0, a-1));

        if (st[M+b] < p) upd(b, p);
    }

    cout << st[1] << "\n";
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}