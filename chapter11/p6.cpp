#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101010];
int col[101010] = {};

bool dfs(int x) {
    for (auto i : adj[x]) {
        if (col[i] == col[x]) return false;
        if (col[i] == 3-col[x]) continue;
        col[i] == 3-col[x];

        if (!dfs(i)) return false;   
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i=0, a, b; i<M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    col[1] = 1;


}