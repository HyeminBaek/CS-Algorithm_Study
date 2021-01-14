#include <iostream>

using namespace std;

int N;
int stair[301];
int dp[301];

int main(int argc, const char * argv[]) {
    cin>>N;
    for(int i=1;i<=N;i++)    cin>>stair[i];
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    for(int i=3;i<=N;i++){
        dp[i] = max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
    }
    cout<<dp[N];
    return 0;
}
