#include<iostream>
#include<string>
using namespace std;
int T, dr[4] = { 1,-1,0,0 }, dc[4] = { 0,0,1,-1 };
string map[16];
bool visit[16][16];
int DFS(int r, int c) {
    if (map[r][c] == '3') {
        return 1;
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= 16 || nc < 0 || nc >= 16 || map[nr][nc] == '1' || visit[nr][nc]) continue;
        visit[nr][nc] = true;
        ret |= DFS(nr, nc);

    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int tc = 1; tc <= 10; tc++) {
        cin >> T;

        for (int i = 0; i < 16; i++) {
            cin >> map[i];
            for (int j = 0; j < 16; j++) {
                visit[i][j] = false;
            }
        }

        int ans = 0;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (map[i][j] == '2') {
                    visit[i][j] = true;
                    ans = DFS(i, j);
                    break;
                }
            }
        }
        printf("#%d %d\n", tc, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}