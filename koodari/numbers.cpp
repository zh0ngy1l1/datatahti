#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand (time(NULL));
    int guess = 101;
    int guessesleft = 7;
    int secret = rand() % 101;
    cout << "guess the number between 0 and 100.\n";
    while (guessesleft > 0)
    {
        cout << "you have " << guessesleft << " guesses left.\nyour guess? ";
        cin >> guess;
        if (guess < secret)
        {
            cout << "guess is too small.\n";
        }
        else
        {
            if (guess > secret)
            {
                cout << "guess is too large\n";
            }
            else
            {
                cout << "you win. " << secret;
                break;
            }
        }
        guessesleft --;
    }
    cout << "game over. the number is " << secret << ".\n";
}