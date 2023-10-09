// https://cses.fi/dt/task/349, 9.10.2023
 
#include <iostream>
using namespace std;
#define ll long long

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    int m;
    ll q;
    cin >> n;
    cin >> m;
    cin >> q;
    
    int rows[n][m];
    string current;

    for (int i = 0; i < n; i++)
    {
        cin >> current;
        rows[i][0] = (current[0] == '*') ? 1 : 0;

        for (int j = 1; j < m; j++)
        {
            rows[i][j] = (current[j] == '*') ? rows[i][j-1] + 1 : rows[i][j-1];
        }
    }
    int y1, x1, y2, x2;
    for (ll _ = 0; _ < q; _++) {
        cin >> y1;
        cin >> x1;
        cin >> y2;
        cin >> x2;

        for (int i = y1 -1 ; i < y2 ; i ++) {
            cout << (rows[i][x2 - 1] - rows[i][x1 - 1] )
        }


    }

}

// g++ -o <name-you-want-to-give> source.cpp
// n, m, q = tuple([int(i) for i in input().split()])
// rows = []
// for _ in range(n):
//     line = input()
//     rows.append([i for i in range(m) if line[i] == "*"])
// output = ""

// for _ in range(q):
//     result = 0
//     a = 0
//     b = 0
//     rect = [int(i) - 1 for i in input().split()]
//     for row in rows[rect[0]:rect[2] + 1]:
//         for i in row:
//             if i >= rect[1]:
//                 break
//             a += 1
//         for j in row[::-1]:
//             if j <= rect[2]:
//                 break
//             b += 1
//         result = result + len(row) - a - b
//     output = output + str(result) + "\n"
 
// #print(output[:-1])
// print("success")
