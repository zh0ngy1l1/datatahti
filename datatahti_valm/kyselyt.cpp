#include <iostream>
#include <vector>
using namespace std;
#define ll long long



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n, q;
    cin >> n;
    cin >> q;

    ll grid[n];
    ll sumgrid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];    
        sumgrid[i] = grid[i];
        if (i > 0) {
            sumgrid[i] = sumgrid[i] + sumgrid[i - 1];
        }
    }
    
    int a, b;

    for (int i = 0; i < q; i++) {
        cin >> a;
        cin >> b;
        if (a==1){
            cout << sumgrid[b-1] << endl;
        } else {
            cout << sumgrid[b-1] - sumgrid[a-2] << endl;
        }
    }
    
    
}

// def main(): 
//     n, q = tuple(input().split(" ")) # constant
//     taulukko = [int(i) for i in input().split(" ")] # O(n)
//     sums = taulukko[:] # O(n)
//     for i in range(1,  int(n)): # O(n^2) but small
//         sums[i] = sums[i] + sums[i-1]

//     output = ""
//     for _ in range(int(q)): 
//         line = input()
//         space = line.find(" ")
//         a = int(line[:space])
//         b = int(line[space+1:])
//         if a == 1:
//             output = output + str(sums[b - 1]) + "\n"
//         else:
//             output = output + str(sums[b - 1] - sums[a - 2]) + "\n"
//     #print(output[:-1])
//     print("success")

