#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 유클리드 소수 알고리즘, gcd

int n;          // 2~100
int a[100];     // 1~10억
vector<int> v;  // 나머지 같은 수끼리의 차
vector<int> ans;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int gcd_many(vector<int>& v) {
    int result = v[0];
    for (int i = 1; i < v.size(); ++i) {
        result = gcd(result, v[i]);
        if (result == 1) return 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 1; i < n; ++i) {
        v.push_back(a[i] - a[i - 1]);
    }

    int g = gcd_many(v);
    for (int i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            ans.push_back(i);
            ans.push_back(g / i);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
