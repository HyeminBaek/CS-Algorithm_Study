#include<iostream>
#include<string>
using namespace std;
int T;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> s;
        int answer = 0;
        int m = s.size() > 10 ? 10 : s.size();
        for (int i = 0; i < m; i++) {
            int idx = 0;
            bool f = true;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != s[idx]) {
                    f = false;
                    break;
                }
                idx = (idx + 1) % (i + 1);
            }
            if (f) {
                answer = i + 1;
                break;
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}