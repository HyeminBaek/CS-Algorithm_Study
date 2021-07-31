#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tc;
string s;

string solve() {
    // 100
    // 9999
    // 588235
    // 60221409000
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> s;
        cout << '#' << t << ' ' << solve() << '\n';
    }

    return 0;
}
