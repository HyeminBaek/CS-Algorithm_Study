#include<iostream>
#include <string>
using namespace std;
 
string three(int i)
{
}
int main(int argc, char** argv)
{
        int N; cin>>N;
        for(int i =1;i<=N;i++)
        {
            string s = to_string(i), temp ="";
            for(int j =0;j<s.length();j++)
            {
                if(s[j]=='3'||s[j]=='6'||s[j]=='9') temp+='-';
            }
             
            if(temp=="") cout<<i<<" ";
            else cout<<temp<<" ";
        }
 
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
About
