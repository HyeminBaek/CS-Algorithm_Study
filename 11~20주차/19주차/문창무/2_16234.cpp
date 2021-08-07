#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int a[50][50];
int visited[50][50];
int n, l, r, uPeople, uCountry, ans;

void dfs(int x, int y, vector<pii>& open) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (visited[nx][ny]) continue;

        int diff = abs(a[x][y] - a[nx][ny]);
        if (l <= diff && diff <= r) {
            uPeople += a[nx][ny];
            uCountry++;
            visited[nx][ny] = true;
            open.push_back({nx, ny});
            dfs(nx, ny, open);
        }
    }
}

bool move() {
    bool ret = false;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            vector<pii> open;
            uPeople = 0;
            uCountry = 0;
            dfs(i, j, open);

            if (open.size()) {
                ret = true;
                for (int k = 0; k < open.size(); k++) {
                    const auto& [r, c] = open[k];
                    a[r][c] = uPeople / uCountry;
                }
            }
        }
    }

    return ret;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (1) {
        if (!move()) break;
        ans++;
    }
    cout << ans;
    return 0;
}
