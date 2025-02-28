#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX-1

int dis[101010];
vector<pair<int, int>> adj[101010];

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i=0, a, b, c; i<M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i=2; i<N+1; i++) dis[i] = INF;
    cout << INF << endl;



}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}