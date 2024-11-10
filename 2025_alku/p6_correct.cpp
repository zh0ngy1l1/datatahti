#include <bits/stdc++.h>
#define INF LONG_LONG_MAX/2 + 1;
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    ll global_min = INF;
    ll a;
    vector<ll> pieces(N, 1);
    vector<ll> s;
    vector<ll> m(N);
    for (ll _ = 0; _ < N; _++) {
        cin >> a;
        s.push_back(a);
        global_min = min(global_min, a);
    }
    sort(s.rbegin(), s.rend());
    for (ll i = 0; i < N; i++) m[i]=s[i];

    //for (auto i: s) cout << i << " ";cout << endl;

    ll max_index;
    for (ll _ = 0; _ < M; _++) {
        // find the index of the piece we should cut
        max_index = 0;        
        for (ll i = 0; i < N; i++) {
            if (m[i] > m[max_index]) max_index = i;
            else if (m[i] == m[max_index] && s[i]*(pieces[max_index] + 1) > s[max_index]*(pieces[i] + 1)) max_index = i;
        }

        
        // cut the piece
        pieces[max_index]++;
        m[max_index] = (s[max_index]-1)/pieces[max_index] + 1;
        global_min = min(global_min, s[max_index]/pieces[max_index]);

        // find maximum index again
        max_index = 0;        
        for (ll i = 0; i < N; i++) {
            if (m[i] > m[max_index]) max_index = i;
        }
        cout << m[max_index] - global_min << " ";
    }
    cout << "\n";
}
