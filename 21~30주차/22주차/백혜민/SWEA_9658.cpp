#include<iostream>
#include <string>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T; cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin >> s;
 
        char a[3] = { s[0],s[1],s[2] };
 
        if (a[2] - '0' >= 5)
        {
            if (a[1] == '9')    a[1] = '*';
            else a[1] += 1;
        }
        if (a[1] == '*')
        {
            a[1] = '0';
 
            if (a[0] == '9')    a[0] = '*';
            else a[0] += 1;
        }
 
        cout << "#" << test_case << " ";
        if(a[0]=='*') cout << 1 << "." << a[1] << "*10^" << s.length() << "\n";
        else cout<<a[0] << "." << a[1] << "*10^" << s.length()-1 << "\n";
    }
 
return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
