#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e18
#define int unsigned long long
typedef vector<int> vi;
 
 
int calc(vi s, int k) {
    int sum = 0;
    for (int i = 0; i < (int) s.size(); i++) sum += k/s[i];
    return sum;
}
 
signed main() {
	int n, m;
	cin >> n >> m;
    vi s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int a = 1;
    int b = INF;
    int mid;
 
    while (a < b) {
        //printf("%llu, %llu, %llu\n", a, b, mid);
        mid = (a+b)/2;
        if (calc(s, mid) < m) a = mid + 1;
        else b = mid;
    }
    cout << a << endl;
}