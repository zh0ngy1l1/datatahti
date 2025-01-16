#include <bits/stdc++.h>
using namespace std;

const int M = (1<<17);
int st[2*M] = {0};

void upd(int k, int x) {
    k += M;
    st[k] = x;
    for (k/=2; k>0; k/=2) st[k] = st[2*k] + st[2*k + 1];
}

void solve() {
    int N;
    cin >> N;

    int S[N];
    unordered_map<int, int> count;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        count[S[i]]++;
    }
    for (auto m : count) upd(m.first, m.second);

    int p[M] = {0};

    for (int i = 0; i < M; i++) {
        int n = i + M;

        while (n % 2 == 0) n /= 2;

        int next_pwr = 1;
        while (next_pwr < n) next_pwr *= 2;
        int inv = n^(next_pwr-1);

        int b = 0;
        do {
            p[i] += st[n | b];
        } while (b=(b-inv)&inv);
    }

    int c[M] = {0};

    for (int i = 0; i < M; i++) {
        int n = i + M;

        while (n % 2 == 1) n /= 2;

        int prev_pwr = 1;
        while (prev_pwr <= n) prev_pwr *= 2;
        prev_pwr /= 2;
        n -= prev_pwr;

        int b = 0;
        do {
            c[i] += st[(n & b) + prev_pwr];
        } while (b=(b-n)&n);
    }

    int r[M] = {0};

    for (int i = 0; i < M; i++) {
        int n = i + M;

        while (n % 2 == 0) n /= 2;

        int prev_pwr = 1;
        while (prev_pwr <= n) prev_pwr *= 2;
        prev_pwr /= 2;
        n -= prev_pwr;
        
        int inv = n^(prev_pwr-1); 

        int b = 0;
        do {
            r[i] += st[b+prev_pwr];
        } while (b=(b-inv)&inv);
        r[i] = N - r[i];
    }

    for (int i = 0; i < N; i++) {
        cout << c[S[i]] << " ";
        cout << p[S[i]] << " ";
        cout << r[S[i]] << "\n";
    }
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}