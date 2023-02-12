// https://tie.koodariksi.fi/cpp/2

#include <iostream>

using namespace std;

int main() {
    cout << "Montako riviä? ";
    int n;
    cin >> n;
    // portaikon tulostus
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
