#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int board[10][10];                 // 1일때만 종이 가능
int paper[] = {0, 5, 5, 5, 5, 5};  // 1,2,3,4,5
int ans = INF;

bool checkSquare(int r, int c, int len) {
    for (int i = r; i < r + len; ++i) {
        for (int j = c; j < c + len; ++j) {
            if (!board[i][j]) return false;
        }
    }

    return true;
}

void solve(int r, int c, int cnt) {
    if (r >= 10) {
        ans = min(ans, cnt);
        return;
    } else if (c >= 10) {
        solve(r + 1, 0, cnt);
        return;
    } else if (board[r][c] == 0) {
        solve(r, c + 1, cnt);
        return;
    }

    for (int len = 1; len <= 5; ++len) {
        if (!paper[len]) continue;
        if (r + len > 10 || c + len > 10) continue;  // 9+1>10, 9+2>10
        if (!checkSquare(r, c, len)) continue;

        for (int i = r; i < r + len; ++i) {
            for (int j = c; j < c + len; ++j) {
                board[i][j] = 0;
            }
        }
        ++cnt;
        --paper[len];
        solve(r, c + len, cnt);

        for (int i = r; i < r + len; ++i) {
            for (int j = c; j < c + len; ++j) {
                board[i][j] = 1;
            }
        }
        --cnt;
        ++paper[len];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> board[i][j];
        }
    }

    solve(0, 0, 0);  // r,c,cnt;
    ans == INF ? cout << -1 : cout << ans;

    return 0;
}
