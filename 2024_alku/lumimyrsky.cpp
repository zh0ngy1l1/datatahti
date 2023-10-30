#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Luetaan syöte
    vector<int> path1(10);
    for (int i = 0; i < 10; i++) {
        cin >> path1[i];
    }
    vector<int> path2(10);
    for (int i = 0; i < 10; i++) {
        cin >> path2[i];
    }

    // Kirjoita ratkaisusi tähän
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i < 10; i++) {
        sum1 += abs(path1[i] - path1[i-1]);
        sum2 += abs(path2[i] - path2[i-1]);
    }

    // Tulostetaan vastaus
    cout << (sum1 < sum2 ? "1" : "2") << "\n";
}