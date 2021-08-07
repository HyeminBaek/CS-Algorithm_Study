#include<iostream>
#include<string>
using namespace std;
int N, T;
string s[20];
bool IsOver(int r, int c);
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        bool ans = false;
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < N * N; i++) {
            if (s[i / N][i % N] == 'o') {
                if (IsOver(i / N, i % N)) {
                    ans = true;
                    break;
                }
            }
        }
        cout << "#" << tc << " " << (ans ? "YES" : "NO") << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
bool IsOver(int r, int c) {
    int nr[4] = { r,r,r,r }, nc[4] = { c,c,c,c };
    int ct[4] = { 0,0,0,0 };
    for (int i = 1; i <= 4; i++) {
        nr[0] += 1;
        nc[1] += 1;
        nr[2] += 1;
        nc[2] += 1;
        nr[3] += 1;
        nc[3] -= 1;
        for (int j = 0; j < 4; j++) {
            if (nr[j] >= N || nc[j] >= N || nc[j] < 0) continue;
            if (s[nr[j]][nc[j]] == 'o') ct[j]++;

        }
    }
    return (ct[0] == 4 || ct[1] == 4 || ct[2] == 4 || ct[3] == 4);


}