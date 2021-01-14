#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, T;

int main(int argc, const char * argv[]) {
    cin>>S>>T;
    while(S.size()!=T.size())
    {
        if(T.back()=='A')   T.pop_back();
        else if(T.back()=='B')
        {
            T.pop_back();
            reverse(T.begin(),T.end());
        }
    }
    if(S==T)    cout<<1;
    else cout<<0;
    return 0;
}
