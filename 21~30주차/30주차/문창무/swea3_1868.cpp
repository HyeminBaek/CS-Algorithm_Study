#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

int T, n, ans;
string board[300];
bool around[300][300];  // 8방향 주변에 폭탄유무
bool check[300][300];

void bfs(int sr, int sc) {  // *지뢰 .노지뢰
    if (board[sr][sc] == '*' || check[sr][sc] || around[sr][sc]) return;
    // 근처에 지뢰 있는경우 - 종료, 지뢰 없는 경우 - 주변도 탐색

    ++ans;
    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        check[r][c] = true;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
            if (check[nr][nc] || board[nr][nc] == '*') continue;

            check[nr][nc] = true;
            if (around[nr][nc] == 0 && board[nr][nc] == '.') q.push({nr, nc});
        }
    }
}

int solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bfs(i, j);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        memset(check, false, sizeof(check));
        ans = 0;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '*') continue;

                for (int d = 0; d < 8; ++d) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
                    if (board[nr][nc] == '*') {
                        around[i][j] = true;
                        break;
                    }
                }
            }
        }
        cout << '#' << test_case << ' ' << solve() << '\n';
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << around[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}
