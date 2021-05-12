#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, k, ans;
int nutrition[11][11];
int feed[11][11];
vector<int> map[11][11];

void springSummer() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j].empty()) continue;

            int death = 0;
            vector<int> tmp;

            sort(map[i][j].begin(), map[i][j].end());
            for (int k = 0; k < map[i][j].size(); k++) {
                int age = map[i][j][k];

                if (nutrition[i][j] >= age) {
                    nutrition[i][j] -= age;
                    tmp.push_back(age + 1);
                } else {
                    death += (age / 2);
                }
            }

            map[i][j].clear();
            for (int k = 0; k < tmp.size(); k++) {
                map[i][j].push_back(tmp[k]);
            }
            nutrition[i][j] += death;
        }
    }
}

void fallWinter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j].empty()) continue;

            for (int k = 0; k < map[i][j].size(); k++) {
                int age = map[i][j][k];

                if (age % 5 == 0) {
                    for (int a = 0; a < 8; a++) {
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

                        map[nx][ny].push_back(1);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            nutrition[i][j] += feed[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> feed[i][j];
            nutrition[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y].push_back(z);
    }

    for (int i = 0; i < k; i++) {
        springSummer();
        fallWinter();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += map[i][j].size();
        }
    }

    cout << ans;
    return 0;
}
