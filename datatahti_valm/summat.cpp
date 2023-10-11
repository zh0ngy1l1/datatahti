// https://cses.fi/dt/task/353, 10.10.2023

#include <iostream>
using namespace std;
#define ll long long

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    int q;
    cin >> n;
    cin >> q;

    ll values[n];
    ll sums[n];

    ll current;

    cin >> current;
    values[0] = current;
    sums[0] = current;

    for (int i = 1; i < n; i++)
    {
        cin >> current;
        values[i] = current;
        sums[i] = sums[i - 1] + current;
    }

    char operation;
    ll aork, borx;

    for (int _ = 0; _ < q; _++)
    {
        cin >> operation;
        cin >> aork;
        cin >> borx;

        if (operation == '?')
        {
            if (aork == 1)
            {
                cout << sums[borx - 1] << endl;
            }
            else
            {
                cout << sums[borx - 1] - sums[aork - 2] << endl;
            }
        }
        else
        {
            int d = borx - values[aork - 1];
            // cout << "changing value from " << values[aork-1] << " to " << borx << ", change: " << d << endl;
            // cout << "old sum " << sums[aork-1];
            for (int i = aork - 1; i < n; i++)
            {
                sums[i] += d;
            }

            // cout << " changes to " << sums[aork-1] << endl;
            values[aork - 1] = borx;
        }
    }
}
