#include<iostream>
#include<string>
using namespace std;
int T;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> s;
        int ans = 0;
        int nbit = '0';
        for (int i = 0; i < s.size(); i++) {
            if (nbit != s[i]) {
                nbit = s[i];
                ans++;
            }

        }
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}