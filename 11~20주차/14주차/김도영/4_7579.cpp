#include <iostream>

const int MAX = 10001;
using namespace std;

int n, m, ans = 1000000000;
int memory[101], cost[101];
int dp[101][MAX];

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> memory[i];
    }
    for(int i=1; i<=n; i++){
        cin >> cost[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<MAX; j++){
            dp[i][j] = dp[i-1][j];
            if(cost[i] <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);   
            }

            if(m <= dp[i][j])
                ans = min(ans, j);
        }
    }

    cout << ans;
}