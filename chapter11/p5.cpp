#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010101];
bool vis[1010101] = {};
int src[1010101] = {};

void solve() {
    int N, M;
    cin >> N >> M;

    for (int r=0; r<N; r++) {
        for (int c=0; c<M; c++) {
            if (r > 0) adj[r*M+c].push_back(r*M+c-M);
            if (r < N-1) adj[r*M+c].push_back(r*M+c+M);
            if (c > 0) adj[r*M+c].push_back(r*M+c-1);
            if (c < M-1) adj[r*M+c].push_back(r*M+c+1);
        }
    }

    int A=0, B=0;
    for (int r=0; r<N; r++) {
        for (int c=0; c<M; c++) {
            char x;
            cin >> x;
            if (x == '#') vis[r*M+c] = true;
            if (x == 'A') A = r*M+c;
            if (x == 'B') B = r*M+c;
        }
    }

    queue<int> q;
    q.push(A);
    vis[A] = true;
    src[A] = -1;

    while (!q.empty()) {
        int s = q.front(); q.pop();
        if (s == B) break;

        for (auto i : adj[s]) {
            if (vis[i]) continue;
            vis[i] = true;
            src[i] = s;
            q.push(i);
        }
    }

    if (!vis[B]) cout << "QAQ\n";
    else {
        cout << "10-4\n";

        string path;
        for (int i = B; i != A; i = src[i]) {
            if (src[i] == i-1) path.push_back('O');
            if (src[i] == i+1) path.push_back('V');
            if (src[i] == i-M) path.push_back('A');
            if (src[i] == i+M) path.push_back('Y');
        }

        cout << path.size() << "\n";

        reverse(path.begin(), path.end());
        cout << path << endl;
    }



}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}