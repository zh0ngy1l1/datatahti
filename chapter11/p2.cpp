#include <bits/stdc++.h>
using namespace std;

bool visited[201010] = {false};
vector<int> adj[201010];


void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;

    for (auto u: adj[s]) dfs(u);
}

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i=0, a, b; i<M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    vector<int> ans;

    int prev_r = 1;
    while (1) {
        int r = 0;
        for (int i=prev_r; i<N+1; i++) if (!visited[i]) {r=i; break;} 
        if (r==0) break;

        prev_r=r;
        ans.push_back(r);
        dfs(r);
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << "1 " << i << "\n";
    }
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}