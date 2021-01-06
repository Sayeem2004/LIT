#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<long long> v(n+1), product(n+1), zero;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    v[i] = x;
    if (i == 1) {
      if (x == 0) {
        product[1] = 1;
        zero.push_back(1);
      } else {
        product[1] = x;
      }
      continue;
    }
    if (i == 2) {
      if (x == 0) {
        product[2] = 1;
        zero.push_back(2);
      } else {
        product[2] = x;
      }
      continue;
    }
    if (x == 0) {
      product[i] = 1;
      zero.push_back(i);
      continue;
    }
    product[i] = (product[i-2] * x) % 1000000007;
  }
  int t; cin >> t;
  while (t--) {
    int s, e; cin >> s >> e;
    if (s%2 != e%2) {
      e--;
    }
    bool br = false;
    if (v[s] == 0 || v[e] == 0) {
      cout << 0 << "\n";
      continue;
    }
    for (auto x : zero) {
      if (s <= x && e >= x && s%2 == x%2) {
        br = true;
        break;
      }
    }
    if (br == true) {
      cout << 0 << "\n";
      continue;
    }
    if (s % 2 == 0) {
      if (s == 2) {
        cout << product[e] << "\n";
      } else {
        cout << product[e] / product[s-2] << '\n';
      }
      continue;
    }
    if (s % 2 == 1) {
      if (s == 1) {
        cout << product[e] << "\n";
      } else {
        cout << product[e] / product[s-2] << '\n';
      }
      continue;
    }
  }
}
