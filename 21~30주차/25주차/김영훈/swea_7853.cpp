#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
string s;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cin >> s;
        ans = 1;
        for (int i = 0; i < s.size(); i++) {
            ll ct = 1;
            int bit = (1 << (s[i] - 'a'));
            if (i > 0) {
                int nbit = (bit | (1 << s[i - 1] - 'a'));
                if (nbit != bit) {
                    ct++;
                    bit = nbit;
                }
            }
            if (i < s.size() - 1) {
                int nbit = (bit | (1 << s[i + 1] - 'a'));
                if (nbit != bit) {
                    ct++;
                }
            }
            ans *= ct;
            ans %= MOD;
        }
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}