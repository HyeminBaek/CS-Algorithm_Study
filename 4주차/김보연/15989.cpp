#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t,n = 0;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> dp(n+1,1);
        dp[1] = 1;
        
        //2로 만들기
        for(int i=2; i<=n; i++)
            dp[i] += dp[i-2];
        
        //3으로 만들기
        for(int i=2; i<=n; i++)
            dp[i] += dp[i-3];
        cout<<dp[n]<<"\n";
    }
    return 0;
}
