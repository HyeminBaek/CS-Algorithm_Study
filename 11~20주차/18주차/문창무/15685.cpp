#include <iostream>
#include <vector>
using namespace std;

// 0세대: (0,0) -> (1,0)
// 1세대: (0,0)-> (1,0) -> (1,-1)
// 2세대: (0,0) -> (1,0) -> (1,-1) -> (0,-1) -> (0,-2)

int dx[4] = {1, 0, -1, 0};  //우상좌하
int dy[4] = {0, -1, 0, 1};

int n, ans;       // 커브 갯수, 사각형갯수
int a[101][101];  // 드래곤커브 꼭지점

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, d, g;  // x,y시작점100, 시작방향0123우상좌하, 세대10
        cin >> x >> y >> d >> g;

        vector<int> v;
        v.push_back(d);
        for (int i = 0; i < g; ++i) {
            for (int j = v.size() - 1; j >= 0; --j) {
                v.push_back((v[j] + 1) % 4);
            }
        }

        a[x][y] = 1;
        for (int dir : v) {
            x += dx[dir];
            y += dy[dir];
            a[x][y] = 1;
        }
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {  // 사각형 체크
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
