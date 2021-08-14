#include <iostream>
#include <set>
using namespace std;
// https://codeforces.com/blog/entry/69230
// priority_queue 대신 multiset이 더 편함
int n, t;      // 소1만 무대크기100만
int d[10001];  // d[i] 1만

// 제일 작으면서 t분 안에 진행 가능한 무대크기k 파라메트릭서치
bool isPossible(int k) {
    multiset<int> mset;
    int p;                      // 소요시간, 인덱스 포인터
    for (p = 1; p <= k; ++p) {  // 1~k까지 댄스
        mset.insert(d[p]);
    }

    while (p <= n) {  // k+1 ~ n 까지 댄스
        mset.insert(d[p] + *mset.begin());
        mset.erase(mset.begin());
        ++p;
    }

    return *mset.rbegin() <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (isPossible(m))
            r = m;
        else
            l = m + 1;
    }

    cout << l;  // 최소값
    return 0;
}
