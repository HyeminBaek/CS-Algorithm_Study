#include <iostream>

using namespace std;

int n;
int sequence[100001];   // idx: 1~100,000
int dp[100001][2]; // dp[i][0]: 0개를 제거했을 때 i번째 까지의 최대 연속합, dp[i][1]: 1개를 제거했을 때 i번째 까지의 최대 연속합

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans=-1001;
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>sequence[i];
    dp[1][1] = dp[1][0] = sequence[1];  // 1개 이상 선택해야 한다는 조건 때문에 dp[1][1]은 0 이 아니고 sequence[1].
    ans = max(dp[1][0],dp[1][1]);
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0]<0 ? sequence[i] : dp[i-1][0] + sequence[i];
        dp[i][1] = max(dp[i-1][1]+sequence[i],dp[i-1][0]);
        ans = max(ans,max(dp[i][1],dp[i][0]));
    }
    cout<<ans;
    return 0;
}
