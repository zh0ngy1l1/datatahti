#include <bits/stdc++.h>
using namespace std;

bool vis[201010] = {false};
int par[201010] = {};
vector<int> adj[201010];

int loop_start = 0;
int loop_end = 0;

void dfs(int s) {
    if (loop_start != 0) return;
    if (vis[s]) return;
    //printf("searching %d; parent is %d\n", s, par[s]);
    vis[s] = true;

    for (auto u: adj[s]) {
        if (u == par[s]) continue;
        if (vis[u]) {
            loop_start = s;
            loop_end = u;
            return;
        }
        par[u]=s;
        dfs(u);
        if (loop_start != 0) return;
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

    int prev_r=0;

    while (loop_start == 0) {
        int r = 0;
        for (int i=prev_r+1; i<N+1; i++) if (!vis[i]) {r=i; break;} 
        if (r == 0) break;
        dfs(r);
        prev_r=r;
    }

    if (loop_start == 0) {
        cout << "QAQ\n";
    } else {
        cout << "10-4\n";
        queue<int> q;
        q.push(loop_end);

        for (int i = loop_start; i != par[loop_end]; i=par[i]) q.push(i);
        cout << q.size() << endl;
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
        
    }

}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}