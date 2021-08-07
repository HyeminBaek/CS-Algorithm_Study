#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int n, sr, sc, er, ec;
int a[16][16];  // 1벽 0길 2출발 3도착

bool check[16][16];

bool isPossible() {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    check[sr][sc] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || 16 <= nr || 16 <= nc || a[nr][nc] == 1 || check[nr][nc]) continue;

            q.push({nr, nc});
            check[nr][nc] = true;
        }
    }

    if (check[er][ec]) return true;
    return false;
}

int main() {
    for (int t = 0; t < 10; ++t) {
        cin >> n;
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                scanf("%1d", &a[i][j]);
                if (a[i][j] == 2) {
                    sr = i;
                    sc = j;
                }
                if (a[i][j] == 3) {
                    er = i;
                    ec = j;
                }
            }
        }

        memset(check, false, sizeof(check));
        cout << '#' << n << ' ' << isPossible() << '\n';
    }

    return 0;
}
