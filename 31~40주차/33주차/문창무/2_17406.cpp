#include <algorithm>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>
#define INF 987654321
using namespace std;

int n, m, k, ans = INF;
int board[50][50];
int cpy_board[50][50];
int tmp_board[50][50];
vector<tuple<int, int, int>> permu;

void rotate(int r, int c, int s) {  // 시계방향으로 한칸씩 이동
    memcpy(tmp_board, cpy_board, sizeof(board));
    for (int ss = 1; ss <= s; ++ss) {  // 안쪽부터 돌리기
        // (r-s,c-s)~(r-s, c+s)
        // (r-s, c+s)~(r+s, c+s)
        // (r+s, c+s)~(r+s, c-s)
        // (r+s, c-s)~(r-s, c-s)
        for (int j = c - ss; j < c + ss; ++j) {  // 오른쪽이동
            tmp_board[r - ss][j + 1] = cpy_board[r - ss][j];
        }
        for (int i = r - ss; i < r + ss; ++i) {  // 아래이동
            tmp_board[i + 1][c + ss] = cpy_board[i][c + ss];
        }
        for (int j = c + ss; j > c - ss; --j) {  // 왼쪽이동
            tmp_board[r + ss][j - 1] = cpy_board[r + ss][j];
        }
        for (int i = r + ss; i > r - ss; --i) {  // 위로 이동
            tmp_board[i - 1][c - ss] = cpy_board[i][c - ss];
        }
    }

    memcpy(cpy_board, tmp_board, sizeof(board));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        int r, c, s;
        cin >> r >> c >> s;
        permu.push_back({r - 1, c - 1, s});
    }
    sort(permu.begin(), permu.end());

    do {
        memcpy(cpy_board, board, sizeof(board));

        for (int i = 0; i < k; ++i) {
            const auto& [r, c, s] = permu[i];
            rotate(r, c, s);
        }

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += cpy_board[i][j];
            }

            ans = min(ans, sum);
        }
    } while (next_permutation(permu.begin(), permu.end()));

    cout << ans;
    return 0;
}
