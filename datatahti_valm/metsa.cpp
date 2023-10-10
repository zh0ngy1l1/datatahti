// https://cses.fi/dt/task/349, 9.10.2023
 
#include <iostream>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    ll q;
    cin >> n;
    cin >> m;
    cin >> q;
    
    int rows[n][m];
    string current;

    for (int i = 0; i < n; i++)
    {
        cin >> current;
        rows[i][0] = (current[0] == '*') ? 1 : 0;

        for (int j = 1; j < m; j++)
        {
            rows[i][j] = (current[j] == '*') ? rows[i][j-1] + 1 : rows[i][j-1];
        }
    }
    int y1, x1, y2, x2;
    for (ll _ = 0; _ < q; _++) {
        cin >> y1;
        cin >> x1;
        cin >> y2;
        cin >> x2;
        
        int sum = 0;

        if (x1 == 1) {
            for (int i = y1 - 1 ; i < y2 ; i ++) {
                sum += (rows[i][x2 - 1]);
            }
        } else {
            for (int i = y1 - 1 ; i < y2 ; i ++) {
                sum += (rows[i][x2 - 1] - rows[i][x1 - 2] );
            }
        }
        cout << sum << endl;

    }

}
