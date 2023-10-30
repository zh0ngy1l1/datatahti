// https://cses.fi/dt/task/326, 27.10.2023

#include <iostream>
using namespace std;
#define ll long long

const ll big = 1 << 16;
struct DividingArr {
    int size;
    DividingArr(int n, ll whole[], ll sums[]) {
        ll whole_array[n];
        ll prefix_sums[n];
        copy(whole, whole_array);
    }


    int algorithm() {
        for (int i = head_index; i < big; i++)
        {
            /* code */
        }
        return 0;
    }
}

int main()  {
    int n;
    int k;
    cin >> n >> k;
    ll whole_array[n];
    ll prefix_sums[n];

    cin >> whole_array[0];
    prefix_sums[0] = whole_array[0];
    for (int i = 1; i < n; i++)
    {
        cin >> whole_array[i];
        prefix_sums[i] = prefix_sums[i-1] + whole_array[i];
    }
    
    cout << prefix_sums[n-1] << endl;


}