#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a;
	cin >> n;

	unordered_set<int> s;
	for(int _=0; _<n; _++) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size();
}
