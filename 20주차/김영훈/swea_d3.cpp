#include<iostream>
#include<string>
using namespace std;
string s[100];
int Search(int r, int c) {
    int ret = 0;

    int num = 1;
    int idx1 = c - 1;
    int idx2 = c + 1;
    while (1) {
        if (idx1 < 0 || idx2 >= 100 || s[r][idx1] != s[r][idx2]) {
            break;
        }
        num += 2;
        idx1--;
        idx2++;
    }
    ret = ret < num ? num : ret;

    num = 0;
    idx1 = c;
    idx2 = c + 1;
    while (1) {
        if (idx1 < 0 || idx2 >= 100 || s[r][idx1] != s[r][idx2]) {
            break;
        }
        num += 2;
        idx1--;
        idx2++;
    }
    ret = ret < num ? num : ret;

    num = 1;
    idx1 = r - 1;
    idx2 = r + 1;
    while (1) {
        if (idx1 < 0 || idx2 >= 100 || s[idx1][c] != s[idx2][c]) {
            break;
        }
        num += 2;
        idx1--;
        idx2++;
    }
    ret = ret < num ? num : ret;

    num = 0;
    idx1 = r;
    idx2 = r + 1;
    while (1) {
        if (idx1 < 0 || idx2 >= 100 || s[idx1][c] != s[idx2][c]) {
            break;
        }
        num += 2;
        idx1--;
        idx2++;
    }
    ret = ret < num ? num : ret;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;



    for (int tc = 1; tc <= 10; tc++) {
        cin >> T;
        for (int i = 0; i < 100; i++) {
            cin >> s[i];
        }
        int answer = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int r = Search(i, j);
                answer = answer < r ? r : answer;
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}