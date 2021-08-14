#include <iostream>
#include <set>
#include <string>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int r, c;
string a[1001];

bool isPossible(int n) {
    set<string> set;
    for (int i = 0; i < c; ++i) {
        string tmp;
        for (int j = n; j <= r; ++j) {
            tmp += a[j][i];
        }

        if (set.find(tmp) != set.end()) return false;
        set.insert(tmp);
    }

    return true;
}

int main() {
    FASTIO;
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        cin >> a[i];
    }

    int s = 1, e = r;
    while (s <= e) {  // row 시작 위치 찾기
        int mid = (s + e) / 2;
        if (isPossible(mid))  // 더 내려도 됨
            s = mid + 1;
        else
            e = mid - 1;
    }

    cout << e - 1;  // 첫줄 삭제 빼고
    return 0;
}
