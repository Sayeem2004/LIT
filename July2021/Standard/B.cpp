// Ivan Wei & Andrew Juang
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using point = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<point> points;

    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    if(points.size() == 1) {
        cout << 1;
    } else {
        int maxline = 0;
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i + 1; j < points.size(); ++j) {
                int pts = 2;

                int slopex = points[j].first - points[i].first;
                int slopey = points[j].second - points[i].second;

                int g = __gcd(slopex, slopey);
                slopex /= g;
                slopey /= g;
                bool down = false;
                if(slopex < 0 ^ slopey < 0) {
                    down = true;
                }
                slopex = abs(slopex);
                slopey = abs(slopey);

                for(int k = 0; k < points.size(); ++k) {
                    if(k != i && k != j) {
                        int slopekx = points[k].first - points[i].first;
                        int slopeky = points[k].second - points[i].second;
                        int kg = __gcd(slopekx, slopeky);
                        slopekx /= kg;
                        slopeky /= kg;
                        bool kdown = false;
                        if(slopekx < 0 ^ slopeky < 0) {
                            kdown = true;
                        }
                        slopekx = abs(slopekx);
                        slopeky = abs(slopeky);

                        if(slopekx == slopex && slopeky == slopey && down == kdown) {
                            ++pts;
                        }
                    }
                }

                maxline = max(pts, maxline);
            }
        }
        cout << maxline << "\n";
    }
}
