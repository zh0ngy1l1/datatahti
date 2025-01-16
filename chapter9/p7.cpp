#include <bits/stdc++.h>
using namespace std;

vector<int> st;
int S = 1;

void upd(int k, int x) {
    k += S;
    st[k] = x;
    for (k/=2; k>0; k/=2) st[k] = st[2*k] + st[2*k + 1];
}

int rq(int a, int b) {
    int s=0;
    a+=S; b+=S;
    while (a <= b) {
        if (a%2==1) s += st[a++];
        if (b%2==0) s += st[b--];
        a/=2; b/=2;
    }
    return s;
}

void upd2(int a, int b) {
    upd(a, st[a+S]-1);
    upd(b, st[b+S]+1);
}

void solve() {
    int N, Q;
    cin >> N >> Q;

    int s[N];
    vector<int> cvec(N);

    for (int i=0; i<N; i++) {
        cin >> s[i];
        cvec[i] = s[i];    
    }

    char o;
    int a, b;

    tuple<char, int, int> queries[Q];

    for (int i=0; i<Q; i++) {
        cin >> o >> a >> b;
        queries[i] = {o, a, b};

        cvec.push_back(b);
        if (o == '?') cvec.push_back(a);
    }

    sort(cvec.begin(), cvec.end());
    cvec.erase(unique(cvec.begin(), cvec.end()), cvec.end());

    int k = cvec.size();
    unordered_map<int, int> cmap;
    for (int i=0; i<k; i++) cmap[cvec[i]] = i;

    while (S < k) S*=2;
    st.resize(2*S);

    for (int i=0; i<N; i++) {
        upd(cmap[s[i]], st[cmap[s[i]] + S] + 1);
    }

    /*for (int i = S; i > 0; i/=2) {
        for (int j = i; j < 2*i; j++) cout << st[j] << " ";
        cout << "\n";
    }*/   

    for (auto q : queries) {
        o = get<0>(q); a = get<1>(q); b = get<2>(q);

        if (o == '?') cout << rq(cmap[a], cmap[b]) << "\n";
        else {
            upd2(cmap[s[a-1]], cmap[b]);
            s[a-1] = b;
        }
    }

}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}