#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int T;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> s;
        sort(s.begin(), s.end());
        bool answer = false;
        if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) {
            answer = true;
        }
        cout << "#" << tc << " " << (answer ? "Yes" : "No") << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}