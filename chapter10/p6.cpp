#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    int S[N];
    int nums[N];

    int c[N];
    int p[N];
    int r[N];

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        nums[i] = S[i];
        c[i]=1;p[i]=1;r[i]=1;
    }

    int x;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            x = nums[i] & nums[j];
            if (x == 0) continue;
            r[i]++; r[j]++;

            if (x == nums[i]) {
                p[i]++; c[j]++;
            }
            if (x == nums[j]) {
                c[i]++; p[j]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        //printf("n: %d; %d %d %d\n", nums[i], c[i], p[i], r[i]);
    }

    for (int i = 0; i < N; i++) cout << c[i] << " ";
    cout << "\n";

    
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    solve();
}