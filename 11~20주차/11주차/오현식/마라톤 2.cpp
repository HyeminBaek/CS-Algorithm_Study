#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int,int>   Pos;

int N, K;
Pos checkPoints[501]; //idx: 1~500
int dp[501][501];   // dp[N][K]: K개 건너뛰고 1에서 N까지 가는 최단거리

int getManhattanDistance(int checkPoint1, int checkPoint2){
    return abs(checkPoints[checkPoint1].first-checkPoints[checkPoint2].first) + abs(checkPoints[checkPoint1].second-checkPoints[checkPoint2].second);
}

int getMinimumDistance(int n, int k){
    if(dp[n][k]!=INT_MAX) return dp[n][k];
    if(n-k==2)  return dp[n][k] = getManhattanDistance(1,n);
    
    for(int i=0;i<=k;i++){
        dp[n][k] = min(dp[n][k], getMinimumDistance(n-1-i,k-i)+getManhattanDistance(n-1-i,n));
    }
    return dp[n][k];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&dp[0][0],&dp[500][500]+1,INT_MAX);
    int x, y;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>x>>y;
        checkPoints[i] = Pos(x,y);
    }
    cout<<getMinimumDistance(N,K);
    return 0;
}
