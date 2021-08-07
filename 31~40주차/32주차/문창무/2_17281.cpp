#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int a[50][9];  // 이닝 50

int solve(vector<int>& p) {
    int point = 0, hIdx = 0;  // 점수, 타자인덱스

    for (int i = 0; i < n; ++i) {
        vector<int> runner(8);  // 0,1,2,3베이스, 4,5,6,7득점
        int out = 0;            // 3아웃

        while (out < 3) {
            int hit = a[i][p[hIdx]];
            runner[0] = 1;  // 타자

            if (hit == 0)
                ++out;
            else {  // hit : 1,2,3,4
                for (int j = 3; j >= 0; --j) {
                    if (runner[j]) {
                        runner[j + hit] = runner[j];
                        runner[j] = 0;
                    };
                }
                for (int j = 4; j < 8; ++j) {
                    point += runner[j];
                    runner[j] = 0;
                }
            }

            hIdx = (hIdx + 1) % 9;  // 다음타자
        }
    }

    return point;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    do {
        if (p[3] != 0) continue;

        ans = max(ans, solve(p));
    } while (next_permutation(p.begin(), p.end()));

    cout << ans;
    return 0;
}

// 2
// 0 4 4 4 4 4 4 4 4
// 0 4 4 4 4 4 4 4 4