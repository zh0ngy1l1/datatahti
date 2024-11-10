#include <iostream>
#include <vector>
using namespace std;

struct rinne {
    int x;
    vector<rinne> chlidren;

    rinne() {}

    void set_value(int a) {
        x=a;
    }

    void new_child(rinne &r) {
        chlidren.push_back(r);
    }

    int arvo() {
        for (int i = 0; i < size(chlidren); i++) {
            int a = chlidren[i].arvo();
            x = max(x, a);
        }
        return (x);
    }
};

int main() {
    int n;
    int a, b;
    int c;

    cin >> n;

    rinne rinteet[n];

    for (int _ = 0; _ < n-1; _++)
    {
        cin >> a >> b;
        rinteet[a-1].new_child(rinteet[b-1]);
    }

    for (int i = 0; i < n; i++) {
        cin >> c;
        rinteet[i].set_value(c);
    }

    for (int i = 0; i < n; i++) {
        cout << size(rinteet[i].chlidren) << endl;
    }

    cout << rinteet[0].arvo() << endl;
}