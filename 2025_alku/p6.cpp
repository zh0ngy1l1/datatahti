#include <bits/stdc++.h>
#define INF INT32_MAX/2 + 1;
using namespace std;

int N, M;

int get_n(int a, int b) {
    if (a%b==0) return a/b+1;
    return (a-1)/(b-1)+1;
}

int solve(priority_queue<int> &s, int min_a) {
    int a = s.top();
    s.pop();
    int b = s.top();
    int n = min(get_n(a, b), M+N-(int) s.size());
    for (int i = 2; i <= n; i++) {
        cout << max(b, (a-1)/i+1)-min(min_a, a/i) << " ";
    }
    for (int i = 0; i < a%n; i++) s.push(a/n+1);
    for (int i = 0; i < n-a%n; i++) s.push(a/n);
    return min(min_a, a/n);
}

int main() {
    cin >> N >> M;

    int min_a = INF;
    int a;
    priority_queue<int> s;
    for (int _ = 0; _ < N; _++) {
        cin >> a;
        s.push(a);
        min_a = min(min_a, a);
    }
    for (int _ = 0; _ < 100; _++) {
        min_a = solve(s, min_a);
    }
}