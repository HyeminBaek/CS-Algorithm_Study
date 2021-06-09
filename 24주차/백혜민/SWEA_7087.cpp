#include<iostream>
#include <string>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;  cin>>T;
     
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int abc[26]={0,};
         
        int N; cin>>N;
        for(N;N>0;N--)
        {
            string s; cin>>s;
            abc[s[0]-'A']++;
        }
         
        int answer =0;
        for(int i=0;i<26;i++)
        {
            if(abc[i]==0) break;
            answer++;
        }
         
        cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
