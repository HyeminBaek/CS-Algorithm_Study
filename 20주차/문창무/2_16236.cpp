#include <cstring>
#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, shark = 2, ans;  // n20, shark아기상어초기값2
int map[20][20];
int visited[20][20];
queue<pii> q;

void solve() {
    int x, y, movex = 100, movey = 100, eat = 0;

    while (!q.empty()) {
        int qsize = q.size();

        while (qsize--) {
            const auto& [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (visited[nx][ny]) continue;
                if (map[nx][ny] > shark) continue;

                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;

                if (map[nx][ny] && map[nx][ny] < shark) {
                    if (movex > nx) {
                        movex = nx;
                        movey = ny;
                    } else if (movex == nx) {  // 더 왼쪽에 있는 물고기를 먹는다.
                        if (movey > ny) {
                            movex = nx;
                            movey = ny;
                        }
                    }
                }
            }
        }

        if (movex != 100) {
            eat++;
            if (eat == shark) {
                shark++;
                eat = 0;
            }
            map[movex][movey] = 0;
            int time = visited[movex][movey];

            q = queue<pii>();
            memset(visited, 0, sizeof(visited));

            q.push({movex, movey});
            visited[movex][movey] = time;
            ans = time;

            movex = 100;
            movey = 100;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            //아기상어면 큐에 추가,시간 0으로 표시
            if (map[i][j] == 9) {
                q.push({i, j});
                visited[i][j] = 0;
                map[i][j] = 0;
            }
        }
    }

    solve();

    cout << ans;
    return 0;
}
