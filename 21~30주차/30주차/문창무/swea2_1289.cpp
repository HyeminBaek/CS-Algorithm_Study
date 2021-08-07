#include <iostream>
#include <vector>
using namespace std;

int T;

int solve(string s) {
    vector<int> v(s.length(), 0);  // 0000

    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (v[i] != s[i] - '0') {
            ++cnt;
            int bit = 1 - v[i];

            for (int j = i; j < s.length(); ++j) {
                v[j] = bit;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        string s;
        cin >> s;
        cout << '#' << test_case << ' ' << solve(s) << '\n';
    }

    return 0;
}
