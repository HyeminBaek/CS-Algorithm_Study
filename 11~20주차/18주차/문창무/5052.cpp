#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;  // 50

bool solve(vector<string>& v) {
    int ret = true;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] == v[i].substr(0, v[i - 1].length())) {  // 앞부분과 겹치면 false
            ret = false;
            break;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;             // 10000
        vector<string> v(n);  // 전화번호 10자리 10억
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        if (solve(v))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
