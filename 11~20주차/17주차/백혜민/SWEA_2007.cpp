#include<iostream>
#include <string>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin>>s;
         
        for(int i =1;i<=10;i++)
        {
            string sub = s.substr(0,i);
            string next = s.substr(i,i);
             
            if(sub==next) 
            {
                cout<<"#"<<test_case<<" "<<i<<"\n"; break;
            }
        }
    }
    return 0;
}
About
