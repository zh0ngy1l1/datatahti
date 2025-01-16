#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N, K;
	cin >> N >> K;

	int x, min=1;
    priority_queue<int, vector<int>, greater<int>> 牛;
	for(int _=0; _<K; _++) {
		cin >> x;
        牛.push(x);
        if (x == min) {
            for (int k = min; k == 牛.top(); k++, min++) 牛.pop();
        }
        cout << min << " ";
	}
}