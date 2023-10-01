// https://cses.fi/dt/task/359, 1.10.2023

#include <iostream>
using namespace std;
#define ll long long



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n, q;
    cin >> n;
    cin >> q;

    ll grid[n];
    ll sumgrid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];    
        sumgrid[i] = grid[i];
        if (i > 0) {
            sumgrid[i] = sumgrid[i] + sumgrid[i - 1];
        }
    }
    
    int a, b;

    for (int i = 0; i < q; i++) {
        cin >> a;
        cin >> b;
        if (a==1){
            cout << sumgrid[b-1] << endl;
        } else {
            cout << sumgrid[b-1] - sumgrid[a-2] << endl;
        }
    }
    
    
}
