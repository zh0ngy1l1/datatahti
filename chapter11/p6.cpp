#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101010];
int col[101010] = {};

bool dfs(int x) {
    for (auto i : adj[x]) {
        if (col[i] == col[x]) return false;
        if (col[i] == 3-col[x]) continue;
        col[i] = 3-col[x];
        if (!dfs(i)) return false;   
    }
    return true;
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
    if (!dfs(1)) {
        cout << "QAQ\n";
        return;
    }

    int prev_r = 2;
    while (1) {
        int r = 0;
        for (int i=prev_r; i<N+1; i++) if (col[i]==0) {
            r=i;
            break;
        }
        if (r==0) {
            cout << "10-4" << "\n";
            for (int i = 1; i < N+1; i++) {
                cout << col[i] << " ";
            }
            cout << "\n";
            break;
        }
        col[r] = 1;
        if (!dfs(r)) {
            cout << "QAQ\n";
            break;
        }
        prev_r=r+1;
    }
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}