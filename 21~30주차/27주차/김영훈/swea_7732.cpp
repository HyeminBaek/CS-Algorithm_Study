#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int T, t[2][3];
string s1, s2;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cin >> s1 >> s2;
        for (int i = 0; i < 3; i++) {
            t[0][i] = (s1[3 * i] - '0') * 10 + s1[3 * i + 1] - '0';
            t[1][i] = (s2[3 * i] - '0') * 10 + s2[3 * i + 1] - '0';
        }
        int ans[3] = { 0, };
        ans[2] += t[1][2] - t[0][2];
        if (ans[2] < 0) {
            ans[1]--;
            ans[2] += 60;
        }
        else if (ans[2] >= 60) {
            ans[2] -= 60;
            ans[1]++;
        }
        ans[1] += t[1][1] - t[0][1];
        if (ans[1] < 0) {
            ans[0]--;
            ans[1] += 60;
        }
        else if (ans[1] >= 60) {
            ans[0]++;
            ans[1] -= 60;
        }
        ans[0] += t[1][0] - t[0][0];
        if (ans[0] < 0) {
            ans[0] += 24;
        }
        cout << "#" << tc << " ";
        cout << setw(2) << setfill('0') << ans[0] << ":" << setw(2) << setfill('0') << ans[1] << ":" << setw(2) << setfill('0') << ans[2] << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}