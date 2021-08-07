#include<iostream>
#include<string>
using namespace std;
int L;
string s[8];
int Search(int r, int c) {
    int ret = 2;
    int idx1 = c, idx2 = ((L % 2 == 1) ? c : c + 1);
    for (int i = 0; i <= (L - 1) / 2; i++) {
        if (idx1 < 0 || idx2 >= 8 || s[r][idx1] != s[r][idx2]) {
            ret--;
            break;
        }
        idx1--;
        idx2++;
    }
    idx1 = r, idx2 = ((L % 2 == 1) ? r : r + 1);
    for (int i = 0; i <= (L - 1) / 2; i++) {
        if (idx1 < 0 || idx2 >= 8 || s[idx1][c] != s[idx2][c]) {
            ret--;
            break;
        }
        idx1--;
        idx2++;
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    for (int tc = 1; tc <= 10; tc++) {
        cin >> L;
        for (int i = 0; i < 8; i++) {
            cin >> s[i];
        }
        int answer = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                answer += Search(i, j);
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
