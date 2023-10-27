// https://cses.fi/dt/task/326, 27.10.2023

#include <iostream>
using namespace std;
#define ll long long
int main()  {
    int n;
    int k;
    cin >> n >> k;
    ll whole_array[n + 1];
    ll prefix_sums[n + 1];

    for (int i = 1; i < n + 1; i++)
    {
        cin >> whole_array[i];
        prefix_sums[i] = prefix_sums[i-1] + whole_array[i];
    }
    
       


}