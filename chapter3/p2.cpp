#include <bits/stdc++.h>
using namespace std;

struct S {
	unordered_set<int> s;
	void plus(int a) {
		s.insert(a);
	}
	void minus(int a) {
		s.erase(a);
	}
	void question(int a) {
		if(s.count(a)){
		       cout<<"10-4\n";
		} else {
			cout<<"QAQ\n";
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	char o;
	int a;
	S s;
	for(int _=0; _<k; _++) {
		cin >> o >> a;
		if (o=='+') s.plus(a);
		if (o=='-') s.minus(a);
		if (o=='?') s.question(a);
	}
}
