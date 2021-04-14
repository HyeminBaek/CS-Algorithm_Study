#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a(4, vector<int>(8));  // N극 0, S극 1
int k;                                     // 회전횟수100

void rot(int target, int dir) {  // 톱니, 돌아가는 방향 -1,0,1
    if (dir == -1) {
        rotate(a[target].begin(), a[target].begin() + 1, a[target].end());
    } else if (dir == 1) {
        rotate(a[target].rbegin(), a[target].rbegin() + 1, a[target].rend());
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n, d;
        cin >> n >> d;  // 톱니번호, 방향 1:시계 -1:반시계
        n--;
        int dir[4] = {0};  // 돌아가는지 여부
        dir[n] = d;

        for (int j = n; j < 3; ++j) {  // 기준톱니 오른쪽 방향 돌아가는지 체크
            if (a[j][2] != a[j + 1][6]) dir[j + 1] = -dir[j];
        }
        for (int j = n; j > 0; j--) {  // 왼쪽 돌아가는 지 체크
            if (a[j][6] != a[j - 1][2]) dir[j - 1] = -dir[j];
        }

        for (int j = 0; j < 4; ++j) {
            rot(j, dir[j]);
        }
    }

    int ans = 0;  // 점수 계산
    for (int i = 0; i < 4; i++) {
        if (a[i][0]) ans += (1 << i);
    }

    cout << ans;
    return 0;
}
