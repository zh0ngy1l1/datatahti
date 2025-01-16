#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e18
#define int unsigned long long
typedef vector<int> vi;
 
vi S;
int N, K;
 
int calc(int t) {
    // returns how many segments we get when each has sum <= t.
    int sum=0,  k=0;
    for (int i = 0; i < N; i++) {
        if (sum + S[i] > t) {
            sum = S[i];
            k++;
        } else sum += S[i];
    } 
    if (sum > 0) k++;
    return k;
}
 
signed main() {
	cin >> N >> K;
    S.resize(N);
 
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        m = max(m, S[i]);
    }
 
    int a = 1, b=INF;
    int mid = 0;
    while (a < b) {
        mid = (a+b)/2;
        //printf("%llu, %llu, %llu\n", a, b, mid);
        if (calc(mid) > K) a = mid + 1;
        else b = mid;
    }
    cout << max(a, m) << endl;
}