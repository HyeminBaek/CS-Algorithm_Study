#include <cstring>
#include <iostream>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int map[16][16];
bool check[16][16];
int t, sr, sc;
bool ans;

void dfs(int r, int c) {
    check[r][c] = 1;
    if (map[r][c] == 3) {
        ans = true;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (0 > nr || nr > 16 || 0 > nc || nc > 16) continue;
        if (map[nr][nc] == 1 || check[nr][nc]) continue;

        dfs(nr, nc);
    }
}

void init() {
    ans = false;
    memset(check, false, sizeof(check));
    cin >> t;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 2) {
                sr = i;
                sc = j;
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 10; ++i) {
        init();
        dfs(sr, sc);
        cout << '#' << i << ' ' << ans << '\n';
    }
}
