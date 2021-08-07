#include <iostream>
#include <vector>
using namespace std;

int n;
int a[16][16];

int go(int r, int c, int d) {  // (r,c), 방향1,2,3 가로세로대각선
    if (r == n - 1 && c == n - 1) return 1;

    int ans = 0;
    if (d == 1) {  // 가로+가로, 가로+대각
        if (c + 1 < n && a[r][c + 1] == 0)
            ans += go(r, c + 1, 1);
        if (c + 1 < n && r + 1 < n && a[r + 1][c] == 0 && a[r][c + 1] == 0 && a[r + 1][c + 1] == 0)
            ans += go(r + 1, c + 1, 3);
    }
    if (d == 2) {  // 세로+세로, 세로+대각
        if (r + 1 < n && a[r + 1][c] == 0)
            ans += go(r + 1, c, 2);
        if (r + 1 < n && c + 1 < n && a[r][c + 1] == 0 && a[r + 1][c] == 0 && a[r + 1][c + 1] == 0)
            ans += go(r + 1, c + 1, 3);
    }
    if (d == 3) {  // 대각+가로, 대각+세로, 대각+대각
        if (c + 1 < n && a[r][c + 1] == 0)
            ans += go(r, c + 1, 1);
        if (r + 1 < n && a[r + 1][c] == 0)
            ans += go(r + 1, c, 2);
        if (r + 1 < n && c + 1 < n && a[r + 1][c] == 0 && a[r][c + 1] == 0 && a[r + 1][c + 1] == 0)
            ans += go(r + 1, c + 1, 3);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    cout << go(0, 1, 1);
    return 0;
}
