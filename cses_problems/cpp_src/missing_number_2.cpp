// https://cses.fi/problemset/task/1083/ 18.3.2023

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n;
    cin >> n;

    // Create a boolean array to keep track of numbers that are present
    vector<bool> present(n+1, false);

    // Read n-1 numbers and mark them as present
    for(int i=1; i<n; i++) {
        int num;
        cin >> num;
        present[num] = true;
    }

    // Find the missing number
    int missing_num = 0;
    for(int i=1; i<=n; i++) {
        if(!present[i]) {
            missing_num = i;
            break;
        }
    }

    cout << missing_num << endl;

    return 0;
}
