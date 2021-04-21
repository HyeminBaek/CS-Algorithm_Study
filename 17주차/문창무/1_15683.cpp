#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int n, m;

struct CCTV {
    int type, r, c;
};

void check(vector<vector<int>>& map, vector<vector<int>>& map_copy, int r, int c, int dir) {
    int i = r;
    int j = c;
    while (0 <= i && i < n && 0 <= j && j < m) {
        if (map[i][j] == 6) break;
        i += dr[dir];
        j += dc[dir];
    }
}

// dir 1오른쪽 2아래 3왼쪽 4위
int dfs(vector<vector<int>>& map, vector<CCTV>& cctv, int cctvIdx, vector<int> dir) {
    if (cctv.size() == cctvIdx) {  // 모든 cctv 배치하면 맵 검사
        vector<vector<int>> map_copy(map);
        for (int i = 0; i < cctv.size(); ++i) {
            int type = cctv[i].type;
            int r = cctv[i].r;
            int c = cctv[i].c;

            if (type == 1) {  // 1방향
                check(map, map_copy, r, c, dir[i]);
            } else if (type == 2) {  // 2방향 좌우
                check(map, map_copy, r, c, dir[i]);
                check(map, map_copy, r, c, (dir[i] + 2) % 4);
            } else if (type == 3) {  // 2방향 위오른쪽
                check(map, map_copy, r, c, dir[i]);
                check(map, map_copy, r, c, (dir[i] + 1) % 4);
            } else if (type == 4) {  // 3방향
                check(map, map_copy, r, c, dir[i]);
                check(map, map_copy, r, c, (dir[i] + 1) % 4);
                check(map, map_copy, r, c, (dir[i] + 3) % 4);
            } else if (type == 5) {  // 4방향
                check(map, map_copy, r, c, dir[i]);
                check(map, map_copy, r, c, (dir[i] + 1) % 4);
                check(map, map_copy, r, c, (dir[i] + 2) % 4);
                check(map, map_copy, r, c, (dir[i] + 3) % 4);
            }
        }
        int cnt = 0;
    }

    int ans = INF;  // 8*8 = 64;
    for (int i = 0; i < 4; ++i) {
        dir[cctvIdx] = i;
        int tmp = dfs(map, cctv, cctvIdx + 1, dir);  // dfs

        ans = min(ans, tmp);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<CCTV> cctv;
    vector<int> dir;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] != 0) {
                cctv.push_back({map[i][j], i, j});
                dir.push_back(0);
            }
        }
    }

    cout << dfs(map, cctv, 0, dir);
    return 0;
}
