#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ika;
    cout << "Kuinka vanha olet?";
    cin >> ika;
    cout << ika << "is";
    if (ika < 0 || ika > 120)
    {
        cout << "Mahdotonta";
    }
    else if (ika < 18)
    {
        cout << "Olet alaikäinen";
    }
    else
    {
        cout << "Olet aikuinen";
    }
    cout << endl;
}