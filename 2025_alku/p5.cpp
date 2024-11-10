#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Initialize prefix sum array
    vector<vector<vector<int>>> prefix_lawn(n + 1, vector<vector<int>>(n + 1, vector<int>(26, 0)));
    unordered_set<char> types;
    char current;
    
    // Populate prefix sum array and identify present flower species
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            cin >> current;
            int flower_index = current - 'A';
            types.insert(current); // Track distinct flower species
            
            for (int x = 0; x < 26; x++) {
                prefix_lawn[r][c][x] = prefix_lawn[r][c - 1][x] + prefix_lawn[r - 1][c][x] - prefix_lawn[r - 1][c - 1][x];
            }
            prefix_lawn[r][c][flower_index]++; // Update for current cell
        }
    }
    
    long long solutions = 0;
    int a, b;
    // Iterate over all possible submatrices
    for (int rl = 1; rl <= n; rl++) {
        for (int cl = 1; cl <= n; cl++) {
            for (int rg = rl; rg <= n; rg++) {
                // check if it's doomed to begin with
                bool valid = true;
                for (char flower : types) {
                    int flower_index = flower - 'A';
                    int count = prefix_lawn[rg][n][flower_index]
                                - prefix_lawn[rl - 1][n][flower_index]
                                - prefix_lawn[rg][cl - 1][flower_index]
                                + prefix_lawn[rl - 1][cl - 1][flower_index];
                    if (count == 0) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                a = cl;
                b = n+1;
                while (a < b) {
                    valid = true;
                    int mid = (a + b) / 2;
                    for (char flower : types) {
                        int flower_index = flower - 'A';
                        int count = prefix_lawn[rg][mid][flower_index]
                                    - prefix_lawn[rl - 1][mid][flower_index]
                                    - prefix_lawn[rg][cl - 1][flower_index]
                                    + prefix_lawn[rl - 1][cl - 1][flower_index];
                        if (count == 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) {
                        a = mid + 1;  // Move `a` up since `s[mid]` is less than the target
                    } else {
                        b = mid;      // Keep `b` at `mid`, as `s[mid] >= target`
                    }
                }
                
                solutions += (n-a) + 1;                
            }
        }
    }
    
    cout << solutions << endl;
}
