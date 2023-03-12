// https://cses.fi/alon/task/1068/ 12.3.2023

#include <bits/stdc++.h>
using namespace std;

long algorithm(long number)
{
    if (number % 2 == 0)
    {
        number = number / 2;
    }
    else
    {
        number = 3 * number + 1;
    }
    return number;
}

int main()
{
    long number;
    cin >> number;
    cout << number << " ";
    while (number != 1)
    {
        number = algorithm(number);
        cout << number << " ";
    }
}