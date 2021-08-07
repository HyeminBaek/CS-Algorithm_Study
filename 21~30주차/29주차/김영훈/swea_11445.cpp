#include<iostream>
#include<string>
using namespace std;
int T;
string s1, s2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> s1 >> s2;
        cout << "#" << tc << " ";
        if (s1 + 'a' == s2) {
            cout << 'N';
        }
        else {
            cout << 'Y';
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}