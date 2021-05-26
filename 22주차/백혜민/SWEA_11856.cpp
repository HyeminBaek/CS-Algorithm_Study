#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;  cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin>>s;
        sort(s.begin(),s.end());
         
        bool flag= false;
        if(s[0]==s[1]&&s[3]==s[2]) {
            if(s[1]!=s[2]) flag =true;
        }
        cout<<"#"<<test_case<<" ";
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
