#include<iostream>
#include<string>
#include<utility>
using namespace std;
int N;
string s;
bool check[100];
int eraseNum(int idx1, int idx2);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int tc = 1; tc <= 10; tc++) {
        cin >> N >> s;
        for (int i = 0; i < N; i++) {
            check[i] = true;
        }
        for (int i = 0; i < N - 1; i++) {
            int idx1 = i;
            int idx2 = i + 1;
            while (idx1 >= 0 && !check[idx1]) {
                idx1--;
            }
            while (idx2 < N && !check[idx2]) {
                idx2++;
            }
            if (idx1<0 || idx2>N - 1) continue;
            if (s[idx1] == s[idx2]) {
                check[idx1] = false;
                check[idx2] = false;
            }
        }

        cout << "#" << tc << " ";
        for (int i = 0; i < N; i++) {
            if (check[i]) {
                cout << s[i];
            }
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
