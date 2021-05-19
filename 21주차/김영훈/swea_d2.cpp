#include<iostream>
using namespace std;
int N, num, sz;
char answer[100], c;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        sz = 0;
        for (int i = 0; i < N; i++) {
            cin >> c >> num;

            for (int j = 0; j < num; j++) {
                answer[sz + j] = c;
            }
            sz += num;
        }
        cout << "#" << tc;
        for (int i = 0; i < sz; i++) {
            if (i % 10 == 0) {
                cout << "\n";
            }
            cout << answer[i];
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}