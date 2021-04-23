#include <iostream>
#include <vector>
using namespace std;

// 부분수열의 합 sum이 k가 되는 경우의 수
int n, k, ans;
vector<int> v;

void dfs(int idx, int sum) {
    if (sum > k) return;
    if (sum == k) {
        ans++;
        return;
    }

    for (int i = idx; i < n; ++i) {
        dfs(i + 1, sum + v[i]);
    }
}

void init() {
    ans = 0;
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        init();
        dfs(0, 0);
        cout << '#' << i << ' ' << ans << '\n';
    }

    return 0;
}
