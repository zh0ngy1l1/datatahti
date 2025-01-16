#include<bits/stdc++.h>
using namespace std;

bitset<8> column, diag1, diag2;
bitset<8> 星[8];
int 数 = 0;


void search(int y) {
    if (y == 8) {
        数++;
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+7] || 星[y][x]) continue;
        column[x] = diag1[x+y] = diag2[x-y+7] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+7] = 0;
    }
}

void solve() {
    char c;
    for (int y = 0; y < 8; y++) for (int x = 0; x < 8; x++) {
        cin >> c;
        星[y][x] = (c=='*');
    }

    search(0);
    cout << 数 << endl;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}