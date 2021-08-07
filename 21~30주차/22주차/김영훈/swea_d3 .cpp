#include<iostream>
#include<string>
using namespace std;
int T;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> s;
        int n = stoi(s.substr(0, 3));
        n = (n + 5) / 10;

        int ex = 0;
        if (n == 100) {
            n /= 10;
            ex = s.size();
        }
        else {

            ex = s.size() - 1;
        }

        cout << "#" << tc << " " << n / 10 << '.' << n % 10 << "*10^" << ex << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}