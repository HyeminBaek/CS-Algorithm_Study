#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
// 최적 부분구조: dp[1][n] = min(dp[1][i]+dp[i+1][n]+abs(winner[1][i]-winner[i+1][n])) , i: 1~n-1.
int dp[257][257];   // dp[i][j] :i번째 노드에서 j번째 노드로 구성된 문제의 답.(i:1~256, j:1~256).  * 최종해 : dp[1][n].
int winner[257][257];   // i번째 노드에서 j번째 노드로 구성된 문제에서의 최종 승자.
vector<int> players;

int solve(int left, int right)
{
    if(dp[left][right]!=INT_MAX)  return dp[left][right];

    for(int i=left;i<right;i++)
    {
        int candidate = solve(left,i) + solve(i+1,right);
        candidate += abs(winner[left][i]-winner[i+1][right]);
        if(candidate < dp[left][right])
        {
            dp[left][right] = candidate;
            winner[left][right] = min(winner[left][i], winner[i+1][right]);
        }
    }
    return dp[left][right];
}

int main(int argc, const char * argv[]) {
    int rankOfPlayer;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>rankOfPlayer;
        players.push_back(rankOfPlayer);
    }
    fill(&dp[0][0],&dp[256][256],INT_MAX);
    for(int i=1;i<=n;i++)
    {
        winner[i][i]=players[i-1];
        dp[i][i]=0;
    }
    cout<<solve(1,n);
    return 0;
}
