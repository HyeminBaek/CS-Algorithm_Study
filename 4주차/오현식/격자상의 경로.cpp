#include <iostream>

using namespace std;

int N, M, K;
int dp[16][16];

int main(int argc, const char * argv[]) {
    cin>>N>>M>>K;
    pair<int,int> stopover;
    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
        {
            cnt++;
            if(cnt==K)  {
                stopover=make_pair(i,j);
                break;
            }
        }
    }
    dp[1][1]=1;
    if(K==0){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(i-1>0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
    }
    
    else{
        for(int i=1;i<=stopover.first;i++){
            for(int j=1;j<=stopover.second;j++){
                if(i-1>0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        for(int i=stopover.first;i<=N;i++){
            for(int j=stopover.second;j<=M;j++){
                if(i-1>=stopover.first){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=stopover.second){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
    }
    cout<<dp[N][M];
    return 0;
}
