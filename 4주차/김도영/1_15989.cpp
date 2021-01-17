#include <iostream>

const int MAX = 101;
using namespace std;

int dp[3][MAX];

int main(){
    fill(dp[0], dp[0]+MAX, 1);

    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[2][3] = 1;
    for(int i=4; i<MAX; i++){
        dp[1][i] = dp[0][i-2]+dp[1][i-2];
        dp[2][i] = dp[0][i-3]+dp[1][i-3]+dp[2][i-3];
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[0][n]+dp[1][n]+dp[2][n] << "\n";
    }
}