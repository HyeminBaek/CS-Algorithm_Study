
#include<iostream>
#include<string>
using namespace std;
int T;
string s[4];
int CheckRow() {

    for (int i = 0; i < 4; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < 4; j++) {
            if (s[i][j] == 'O' || s[i][j] == 'T') {
                a++;
            }
            if (s[i][j] == 'X' || s[i][j] == 'T') {
                b++;
            }
        }
        if (a == 4) {
            return 1;
        }
        else if (b == 4) {
            return 2;
        }
    }
    return 0;
}
int CheckCol() {
    for (int i = 0; i < 4; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < 4; j++) {
            if (s[j][i] == 'O' || s[j][i] == 'T') {
                a++;
            }
            if (s[j][i] == 'X' || s[j][i] == 'T') {
                b++;
            }
        }
        if (a == 4) {
            return 1;
        }
        else if (b == 4) {
            return 2;
        }
    }
    return 0;
}
int CheckCross() {
    int a = 0, b = 0;
    for (int i = 0; i < 4; i++) {
        if (s[i][i] == 'O' || s[i][i] == 'T') {
            a++;
        }
        if (s[i][i] == 'X' || s[i][i] == 'T') {
            b++;
        }
    }
    if (a == 4) {
        return 1;
    }
    else if (b == 4) {
        return 2;
    }
    a = 0, b = 0;
    for (int i = 0; i < 4; i++) {
        if (s[3 - i][i] == 'O' || s[3 - i][i] == 'T') {
            a++;
        }
        if (s[3 - i][i] == 'X' || s[3 - i][i] == 'T') {
            b++;
        }
    }
    if (a == 4) {
        return 1;
    }
    else if (b == 4) {
        return 2;
    }
    return 0;
}
int CheckWinner() {
    int r = CheckRow();
    if (r > 0) {
        return r;
    }
    r = CheckCol();
    if (r > 0) {
        return r;
    }
    r = CheckCross();
    if (r > 0) {
        return r;
    }
    return 0;
}
bool CheckFull() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 0; i < 4; i++) {
            cin >> s[i];
        }
        int r = CheckWinner();
        if (r == 0) {
            bool f = CheckFull();
            cout << "#" << tc << " " << (f ? "Draw" : "Game has not completed") << "\n";
        }
        else {
            cout << "#" << tc << " " << ((r == 1) ? 'O' : 'X') << " won\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}