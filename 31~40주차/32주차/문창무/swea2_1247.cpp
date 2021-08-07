#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;

int t, n, sr, sc, er, ec, ans;
vector<pii> a(10);
bool check[10];

int getLen(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void go(int nr, int nc, int depth, int len) {
    if (depth == n) {
        ans = min(ans, len + getLen({nr, nc}, {er, ec}));
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check[i]) continue;

        check[i] = true;
        go(a[i].first, a[i].second, depth + 1, len + getLen({nr, nc}, a[i]));
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        ans = INF;
        memset(check, false, sizeof(check));
        cin >> n >> sr >> sc >> er >> ec;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }

        go(sr, sc, 0, 0);
        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
