#include<iostream>

using namespace std;
double a, b;
int T;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> a >> b;
        cout << "#" << tc;
        if ((1 - a) * b < a * (1 - b) * b) {
            cout << " YES\n";
        }
        else {
            cout << " NO\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}