#include <bits/stdc++.h>
#define INF INT32_MAX/2 + 1;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int a;
    vector<int> pieces(N, 1);
    vector<int> s;
    vector<int> m(N);
    for (int _ = 0; _ < N; _++) {
        cin >> a;
        s.push_back(a);
    }
    sort(s.rbegin(), s.rend());
    int global_min = s.back();
    
    for (int i = 0; i < N; i++) m[i]=s[i];

    //for (auto i: s) cout << i << " ";cout << endl;
    
    int max_index, max_value, minmax, maxmin, d1, d2;
    for (int _ = 0; _ < M; _++) {
        // find the index of the two cuts maxinizing min and minimizing max respectively
        minmax = maxmin = 0;
        for (int i = 0; i < N; i++) {
            if (m[i] > m[minmax]) minmax = i;
            if (s[i]*(pieces[maxmin] + 1) > s[maxmin]*(pieces[i] + 1)) maxmin = i;
        }

        // find max_value among the sticks after we minimize max.
        max_index = minmax ^ 1;
        max_value = (s[minmax]-1)/(pieces[minmax]+1) + 1;
        for (int i = 0; i < N; i++) {
            if (i == minmax) continue;
            if (m[i] >= m[max_index] and m[i] > max_value) {
                max_index = i;
                max_value = m[max_index];
            }
        }
        d1 = max_value - min(global_min, s[minmax]/(pieces[minmax]+1));

        // find max_value among the sticks after we minimize max.
        max_index = maxmin ^ 1;
        max_value = (s[maxmin]-1)/(pieces[maxmin]+1) + 1;
        for (int i = 0; i < N; i++) {
            if (i == maxmin) continue;
            if (m[i] >= m[max_index] and m[i] > max_value) {
                max_index = i;
                max_value = m[max_index];
            }
        }

        d2 = max_value - min(global_min, s[maxmin]/(pieces[maxmin]+1));

        if (d1 > d2) {
            cout << d2 << " ";
            minmax = maxmin;
        } else cout << d1 << " ";

        // cut the piece
        pieces[minmax]++;
        m[minmax] = (s[minmax]-1)/pieces[minmax] + 1;
        global_min = min(global_min, s[minmax]/pieces[minmax]);

        
    }
    cout << "\n";
}
