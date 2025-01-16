#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101010];
bool vis[101010];
int dis[101010] = {0};
int src[101010] = {0};

void solve() {
    int N, M;
    cin >> N >> M;
    for (int _=0, a, b; _<M; _++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;

    while (!q.empty()) {
        int s = q.front(); q.pop();
        if (s == N) {
            break;
        }

        for (auto i : adj[s]) {
            if (vis[i]) continue;
            vis[i] = true;
            dis[i] = dis[s] + 1;
            q.push(i);
            src[i] = s;
        }
    }

    if (!vis[N]) cout << "QAQ\n";
    else {
        cout << "10-4\n";

        stack<int> path;
        for (int i = N; i != 0; i = src[i]) {
            path.push(i);
        }

        cout << path.size() << "\n";

        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}