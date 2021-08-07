#include<iostream>
#include<string>
using namespace std;
int T;
string N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        int num = (N[0] - '0') * 100 + (N[1] - '0') * 10 + (N[2] - '0') + 5;
        num /= 10;
        cout << "#" << tc << " ";
        if (num >= 100) {
            cout << num / 100 << '.' << (num / 10) % 10 << "*10^" << N.size() << "\n";
        }
        else {
            cout << num / 10 << '.' << num % 10 << "*10^" << N.size() - 1 << "\n";
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}