#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int t, n, b, ans;

void dfs(vector<int>& h, int num, int height) {  // 갯수, 인간타워 높이
    if (num == n) {
        if (height >= b) ans = min(ans, height);
        return;
    }

    dfs(h, num + 1, height);
    dfs(h, num + 1, height + h[num]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> b;  // 사람,
        vector<int> h(n);

        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        ans = INF;
        dfs(h, 0, 0);

        cout << '#' << tc << ' ' << ans - b << '\n';
    }

    return 0;
}
