// Mohammad Khan
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> V(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            cin >> V[i][q];
        }
    }
    vector<ll> G;
    for (int i = 0; i < n; i++) {
        ll curr = 1;
        for (int q = 1; q < m; q++) {
            if (V[i][q] != V[i][q-1]) {
                if (V[i][q] == 0) {
                    G.push_back(curr);
                    curr = 1;
                } else {
                    curr = 1;
                }
            } else {
                curr++;
            }
        }
        if (V[i][m-1] == 1) G.push_back(curr);
    }
    sort(G.begin(), G.end());
    reverse(G.begin(), G.end());
    ll sm = 0;
    for (int i = 0; i < k; i++)
        sm += G[i];
    cout << sm << "\n";
}
