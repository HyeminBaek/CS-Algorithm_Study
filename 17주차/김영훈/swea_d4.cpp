#include<iostream>
#include<string>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
string map[16];
bool visit[16][16];
pii d[4] = { pii(0,1),pii(1,0),pii(0,-1),pii(-1,0) };
bool DFS(int r, int c) {

    visit[r][c] = true;

    if (map[r][c] == '3') {

        return true;
    }
    bool ret = false;
    for (int i = 0; i < 4; i++) {
        int nr = r + d[i].first;
        int nc = c + d[i].second;
        if (nr >= 0 && nr < 16 && nc >= 0 && nc < 16) {
            if (!visit[nr][nc] && (map[nr][nc] == '0' || map[nr][nc] == '3')) {
                ret = (ret || DFS(nr, nc));
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int T = 10;
    int t;
    for (int tc = 1; tc <= 10; tc++) {

        cin >> t;

        pii start;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                visit[i][j] = false;
            }
        }
        for (int i = 0; i < 16; i++) {
            cin >> map[i];

            for (int j = 0; j < 16; j++) {
                if (map[i][j] == '2') {
                    start.first = i;
                    start.second = j;
                }
            }

        }


        cout << "#" << t << " " << DFS(start.first, start.second) << "\n";
    }
    return 0;
}