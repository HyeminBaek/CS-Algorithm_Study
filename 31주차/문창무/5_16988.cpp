#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int n, m, ans;      // 20 20
int board[20][20];  //0빈칸 1나 2적
int tmp[20][20];
bool check[20][20];
vector<pii> blank;
vector<pii> enemy;

int kill() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tmp[i][j] == 2 && !check[i][j]) {
                queue<pii> q;
                q.push({i, j});
                check[i][j] = true;
                int blackCnt = 1;
                bool zero = false;

                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if (0 > nr || 0 > nc || n <= nr || m <= nc || check[nr][nc] || tmp[nr][nc] == 1) continue;
                        if (tmp[nr][nc] == 0) {
                            zero = true;
                        }

                        check[nr][nc] = true;
                        q.push({nr, nc});
                        ++blackCnt;
                    }
                }
                if (!zero) {
                    cnt += blackCnt;
                }
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) blank.push_back({i, j});
            if (board[i][j] == 2) enemy.push_back({i, j});
        }
    }

    for (int i = 0; i < blank.size() - 1; ++i) {
        for (int j = i + 1; j < blank.size(); ++j) {
            memcpy(tmp, board, sizeof(board));
            memset(check, false, sizeof(check));

            pii fi = blank[i], se = blank[j];
            tmp[fi.first][fi.second] = 1;
            tmp[se.first][se.second] = 1;
            int cnt = kill();
            ans = max(ans, cnt);
        }
    }

    cout << ans;
    return 0;
}
