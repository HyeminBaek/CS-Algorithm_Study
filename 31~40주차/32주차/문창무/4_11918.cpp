#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

int n, range;
ll ans;
int a[150001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> range;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    // 1. 이전 범위랑 겹칠때 (l <= r)
    // 2. 넘어갈때
    int l = a[0] - range, r = a[0] + range;
    for (int i = 1; i < n; i++) {
        int nowL = a[i] - range;
        int nowR = a[i] + range;

        if (l < nowL) l = nowL;  // 새 범위가 앞에 있으면 교체
        if (l <= r) {            // 새범위랑 기존 범위R이랑 겹치면 겹치는 부분 추가
            ans += (r - l);
            l = r;
        }
        r = nowR;
    }

    cout << ans;
    return 0;
}
