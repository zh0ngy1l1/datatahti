#include<bits/stdc++.h>
using namespace std;

const int MAX_ROWS = 509;
const int MAX_COLS = 1009;

int net[MAX_ROWS][MAX_COLS];
int prefixSum[MAX_ROWS][MAX_COLS];

int totalSum;
int numRows, numCols, numMines;
int minTriangularSum = 1e9;

int fixColumn(int row, int col) {
    if (row % 2 == 0)
        return 2 * col;
    return 2 * col - 1;
}

int main() {
    cin >> numRows >> numCols >> numMines;
    numCols = numCols * 2;

    for (int i = 1; i <= numMines; i++) {
        int row, col;
        char type;
        cin >> row >> col >> type;

        if (type == 'H') {
            net[row][fixColumn(row, col)] = 1;
        } else if (type == 'K') {
            net[row][fixColumn(row, col)] = -10;
        }
    }

    for (int i = 1; i <= numRows; i++)
    {
        for (int j = 1; j <= numCols; j++)
        {
            cout << net[i][j] << " ";
        }
        cout << endl;
    }
    

    for (int i = 1; i <= numRows; i++) {
        for (int j = 1; j <= numCols; j++) {
            totalSum += net[i][j];
            prefixSum[i][j] = prefixSum[i][j - 1] + net[i][j];
        }
    }

    // Iterate through each row in the grid
    for (int i = 1; i <= numRows; i++) {
        // Iterate through each possible column (using numCols / 2)
        for (int j2 = 1; j2 <= numCols / 2; j2++) {

            // Convert the virtual column index to the actual grid column index
            int j = fixColumn(i, j2);
            // Initialize variables to track the triangular sums in upward and downward directions
            int sz = 1;
            int sumUpward = 0, sumDownward = 0;

            // Calculate triangular sums in the upward direction
            while (
                i + sz - 1 <= numRows && 
                j - sz >= 0 && 
                j + sz - 1 <= numCols) 
            {
                // Update the sumUpward by considering the difference between prefix sums
                sumUpward = sumUpward + (prefixSum[i + sz - 1][j + sz - 1] - prefixSum[i + sz - 1][j - sz]);
                // Update the minimum triangular sum encountered so far
                minTriangularSum = min(minTriangularSum, sumUpward);
                // Move to the next layer of the triangle
                sz++;
            }

            // Reset the size variable for the downward direction
            sz = 1;
            // Calculate triangular sums in the downward direction
            while (
                i - sz + 1 >= 1 && 
                j - sz >= 0 && 
                j + sz - 1 <= numCols) 
            {
                // Update the sumDownward by considering the difference between prefix sums
                sumDownward = sumDownward + (prefixSum[i - sz + 1][j + sz - 1] - prefixSum[i - sz + 1][j - sz]);
                // Update the minimum triangular sum encountered so far
                minTriangularSum = min(minTriangularSum, sumDownward);
                // Move to the next layer of the triangle
                sz++;
            }
        }
    }


    cout << totalSum - minTriangularSum << endl;
    return 0;
}
