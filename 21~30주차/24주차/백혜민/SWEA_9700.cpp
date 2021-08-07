#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;  cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        double p,q; cin>>p>>q;
 
        cout<<"#"<<test_case<<" ";
        if(1<p*(2-q)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
