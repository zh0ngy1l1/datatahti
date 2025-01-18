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

    int A=0;
    vector<int> monsters, escapes;
    for (int r=0; r<N; r++) {
        for (int c=0; c<M; c++) {
            char x;
            cin >> x;
            if (x == '#') vis[r*M+c] = true;
            if (x == 'A') A = r*M+c;
            if (x == 'H') monsters.push_back(r*M+c);
            if (x == '.' && (r == 0 || r == N-1 || c == 0 || c == M-1)) escapes.push_back(r*M+c);
        }
    }

    printf("you're at %d\n", A);
    for (auto i : monsters) cout << i << " ";
    cout << "< Monsters\n";
    for (auto i : escapes) cout << i << " ";
    cout << "< Escapes\n";



}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}