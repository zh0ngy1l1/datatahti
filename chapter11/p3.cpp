#include <bits/stdc++.h>
using namespace std;

bool vis[1000000] = {false};
vector<int> adj[1000000];


void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u: adj[s]) dfs(u);
}

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

    for (int r=0; r<N; r++) {
        for (int c=0; c<M; c++) {
            char x;
            cin >> x;
            if (x == '#') vis[r*M+c] = true;
        }
    }
    int a = 0;

    for (int i=0; i < N*M; i++) {
        if (vis[i]) continue;
        dfs(i);
        a++;
    }

    cout << a << "\n";
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}