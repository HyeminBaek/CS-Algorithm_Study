#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Enemy {
    int r, c, d;
    bool operator<(const Enemy& other) const {
        if (d == other.d) return c > other.c;
        return d > other.d;
    }
};

int n, m, d, ans;
int board[15][15];
int tmp[15][15];
vector<int> archer;

void down() {
    for (int i = n - 1; i >= 1; --i)
        for (int j = 0; j < m; ++j)
            tmp[i][j] = tmp[i - 1][j];

    for (int i = 0; i < m; ++i)
        tmp[0][i] = 0;
}

int kill(vector<int>& aPos) {  // (0,1,2)
    int cnt = 0;
    priority_queue<Enemy> pq1, pq2, pq3;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!tmp[i][j]) continue;

            int d1 = (n - i) + abs(aPos[0] - j);
            int d2 = (n - i) + abs(aPos[1] - j);
            int d3 = (n - i) + abs(aPos[2] - j);
            if (d1 <= d) pq1.push({i, j, d1});
            if (d2 <= d) pq2.push({i, j, d2});
            if (d3 <= d) pq3.push({i, j, d3});
        }
    }

    if (!pq1.empty()) {
        Enemy fi = pq1.top();
        tmp[fi.r][fi.c] = 0;
        ++cnt;
    }

    if (!pq2.empty()) {
        Enemy se = pq2.top();
        if (tmp[se.r][se.c]) {
            tmp[se.r][se.c] = 0;
            ++cnt;
        }
    }

    if (!pq3.empty()) {
        Enemy th = pq3.top();
        if (tmp[th.r][th.c]) {
            tmp[th.r][th.c] = 0;
            ++cnt;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> d;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    for (int i = 0; i < m - 3; ++i)
        archer.push_back(0);
    for (int i = 0; i < 3; ++i)
        archer.push_back(1);

    do {
        memcpy(tmp, board, sizeof(board));
        vector<int> aPos;  // {0,1,2}
        for (int i = 0; i < m; ++i) {
            if (archer[i]) aPos.push_back(i);
        }

        int cnt = 0;
        int t = n;
        while (t--) {
            cnt += kill(aPos);
            down();
        }
        ans = max(ans, cnt);
    } while (next_permutation(archer.begin(), archer.end()));

    cout << ans;
    return 0;
}
