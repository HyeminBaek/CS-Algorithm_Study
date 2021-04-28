#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1)  // 집
                home.push_back({i, j});
            else if (map[i][j] == 2)  // 치킨
                chicken.push_back({i, j});
        }
    }

    vector<int> dist(chicken.size());
    for (int i = 0; i < m; ++i) dist[i] = 1;
    sort(dist.begin(), dist.end());  // {1,1,0,0,0} 순열 // 유지되는 치킨집

    int result = -1;
    do {
        int sum = 0;
        for (auto& h : home) {
            vector<int> cDist;  // 치킨거리 저장
            for (int i = 0; i < chicken.size(); ++i) {
                if (!dist[i]) continue;
                auto& s = chicken[i];
                int xd = abs(h.first - s.first);
                int yd = abs(h.second - s.second);
                cDist.push_back(xd + yd);
            }
            sum += *min_element(cDist.begin(), cDist.end());
        }
        if (result < 0 || result > sum) {
            result = sum;
        }
    } while (next_permutation(dist.begin(), dist.end()));
    cout << result << endl;
    return 0;
}
