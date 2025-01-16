//code stolen from cses; submitted at 2024-11-25 16:54:33 by adex720

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
 
    ll t[n];
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
 
    sort(t, t + n);
 
    for (int a = 1; a < n; a++)
    {
        int b = a+1;
        int c = n - 1;
 
        while (b < c)
        {
            int summa = t[a] + t[b] + t[c];
            if (summa < x)
            {
                b++;
            }
            else if (summa > x)
            {
                c--;
            }
            else
            {
                cout << t[a] << " " << t[b] << " " << t[c];
                return 0;
            }
        }
    }
}