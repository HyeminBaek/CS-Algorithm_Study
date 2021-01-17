#include <iostream>

using namespace std;

int dp[301];
int step[301] = {0};

int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        cin >> step[i];
    }

    dp[1] = step[1];
    dp[2] = step[1] + step[2];
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-3]+step[i-1], dp[i-2]) + step[i];
    }

    cout << dp[n];
}