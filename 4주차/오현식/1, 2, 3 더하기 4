#include <iostream>

using namespace std;

int T, n;
int dp[4][10001];  //   [4]:1~3 : maximum of number, [10001]: size of problem

int main(int argc, const char * argv[]) {
    cin>>T;
    dp[1][1]=1;
    dp[2][1]=0;
    dp[3][1]=0;
    dp[1][2]=1;
    dp[2][2]=1;
    dp[3][2]=0;
    dp[1][3]=1;
    dp[2][3]=1;
    dp[3][3]=1;
    for(int i=4;i<=10000;i++)
    {
        dp[1][i]=dp[1][i-1];
        dp[2][i]=dp[1][i-2] + dp[2][i-2];
        dp[3][i]=dp[1][i-3] + dp[2][i-3] + dp[3][i-3];
    }
    for(int i=0;i<T;i++)
    {
        cin>>n;
        cout<<dp[1][n]+dp[2][n]+dp[3][n]<<endl;
    }
    return 0;
}
