#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

struct Pos {
    char t;
    int d, s;  // 소요시간 만족도
};

// 조건 내에서 최대 만족도인 루트
int t, n, m;
int a[36][36];
vector<Pos> v(36);

void solve() {
    // max(만족도), max만족도일때의 경로
}

int main() {
    FASTIO;
    cin >> t;
    for (int tc = 1; tc <= t; ++t) {
        cin >> n >> m;  // 지점갯수35, 휴가기간5
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        // A공항 P관광 H호텔
        for (int i = 0; i < n; + i) {
            char t;
            int d = 0, s = 0;
            cin >> t;
            if (t == 'P') cin >> d >> s;
            v[i] = {t, d, s};
        }

        cout << '#' << tc << ' ';
        solve();
        cout << endl;
    }

    return 0;
}
