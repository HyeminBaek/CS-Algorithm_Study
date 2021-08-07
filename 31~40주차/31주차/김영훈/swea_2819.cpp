#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
int T, dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };
char arr[4][4];
unordered_set<string> uset;
void Search(string s, int r, int c) {
    s += arr[r][c];
    if (s.size() == 7) {
        uset.insert(s);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
        Search(s, nr, nc);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        uset.clear();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                Search("", i, j);
            }
        }
        cout << "#" << tc << " " << uset.size() << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}