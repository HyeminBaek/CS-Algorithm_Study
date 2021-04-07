#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

int n;                  // 4~20, 짝수
vector<vector<int>> v;  // 능력치 1~100
vector<int> permu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    permu.resize(n);
    for (int i = 0; i < n / 2; ++i) {
        permu[i] = 1;
    }
    sort(permu.begin(), permu.end());

    int ans = INF;
    do {
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            if (permu[i] == 0)
                a.push_back(i);
            else
                b.push_back(i);
        }

        int aTeam = 0;
        int bTeam = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (i != j) {
                    int aa = v[a[i]][a[j]];
                    int bb = v[b[i]][b[j]];
                    aTeam += aa;
                    bTeam += bb;
                }
            }
        }

        ans = min(ans, abs(aTeam - bTeam));
    } while (next_permutation(permu.begin(), permu.end()));

    cout << ans;
    return 0;
}
