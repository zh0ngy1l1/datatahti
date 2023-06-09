// https://cses.fi/problemset/task/1083/ 18.3.2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int currentInt;
    long n;

    cin >> n;
    
    unsigned long grandSum = (n * (n+1))>>1;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> currentInt;
        grandSum -= currentInt;
    }
    cout << grandSum;

}