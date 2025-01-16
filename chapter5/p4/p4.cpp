#include <bits/stdc++.h>
using namespace std;
 
const int N = 7;
bitset<N> visited[N];
string moves;
int p = 0;
string expected_moves;
 
void step(int r, int c) {
    if (r == N - 1 && c == 0) {
        if (moves.size() == N * N - 1) p++;
        return;
    }
 
    if (c-1 >= 0 && c + 1 < N && r == 0 && !visited[r][c-1] && !visited[r][c+1]) return; //ceiling
    if (c-1 >= 0 && c + 1 < N && r == N-1 && !visited[r][c-1] && !visited[r][c+1]) return; // floor
    if (r-1 >= 0 && r + 1 < N && c == 0 && !visited[r-1][c] && !visited[r+1][c]) return; // left wall
    if (r-1 >= 0 && r + 1 < N && c == N-1 && !visited[r-1][c] && !visited[r+1][c]) return; // right wall
 
    if (c-1 >= 0 && c + 1 < N && r-1 >= 0 && r + 1 < N && 
        !(visited[r][c-1] ^ visited[r][c+1]) && 
        !(visited[r-1][c] ^ visited[r+1][c])) return;
 
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dir[] = {'Y', 'A', 'V', 'O'};
 
    for (int i = 0; i < 4; i++) {
        if (expected_moves[moves.size()] != dir[i] && expected_moves[moves.size()] != '?') continue;
 
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
 
            moves.push_back(dir[i]);
            visited[nr][nc] = 1;
            step(nr, nc);
            moves.pop_back();
            visited[nr][nc] = 0;
        }
    }
 
 
}
 
void solve() {
    cin >> expected_moves;
 
    visited[0][0] = 1;
    step(0, 0);
    cout << p;
}
 
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    solve();
}