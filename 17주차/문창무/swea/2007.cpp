#include <iostream>
#include <string>
using namespace std;

int t;

int solve(string s) {
    int ret = 1;

    for (int i = 2; i <= 10; ++i) {
        bool flag = true;
        for (int j = 0; j < i; ++j) {
            if (s[j] != s[j + i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ret = i;
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
    cin >> ws;
    for (int i = 1; i <= t; ++i) {
        string s;  // 길이 30
        getline(cin, s);
        cout << '#' << i << ' ' << solve(s) << '\n';  // 마디 최대 10
    }

    return 0;
}
