#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> left, right;
	vector<int> positions;
	int robot_pos = 0;
	string s;
	cin >> s;
	// s = **.*......*.R*...*..
	for (int i=0; i < n; i++){
		if (s[i] == 'R')
			robot_pos = positions.size();
		if (s[i] != '.')
			positions.push_back(i);
	}
	vector<int> distances;
	distances.push_back(positions[0]);

	for (int i=1; i < positions.size(); i++){
		distances.push_back(positions[i]-positions[i-1]);
	}
	
	stack<int> dleft, dright;

	for (int i=1; i <= robot_pos; i++){
		dleft.push(positions[i]-positions[i-1]);
	}
	for (int i=positions.size()-1; i > robot_pos; i--){
		dright.push(positions[i]-positions[i-1]);
	}

	int steps = 0, coins = 0;
	while (true) {
		if (dleft.empty()) {
			while (!dright.empty()){
				steps += dright.top();
				coins++;
				dright.pop();
			}
			break;
		}
		if (dright.empty()) {
			while (!dleft.empty()){
				steps += dleft.top();
				coins++;
				dleft.pop();
			}
			break;
		}

		int l = dleft.top(); 
		int r = dright.top();
		if (l == r) break;
		dleft.pop();
		dright.pop();

		if (l < r) {
			dright.push(l+r);
			steps += l;
		} else {
			dleft.push(l+r);
			steps += r;
		}
		coins++;
	}

	cout << steps << " " << coins << "\n";
	
}
	
