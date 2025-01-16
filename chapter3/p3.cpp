#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	set<int> puuttuvat_lehmat;
	for(int i=0; i<n; i++) {
		puuttuvat_lehmat.insert(i+1);	
	}	

	int a;
	for(int _=0; _<k; _++) {
		cin >> a;
		puuttuvat_lehmat.erase(a);
		cout << *puuttuvat_lehmat.begin() << " ";
	}
}
