#include <iostream>

using namespace std;

int n;
int map[2][17];
int dp[17];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> map[0][i] >> map[1][i];
    }

    int day, ans = 0;
    for(int i=1; i<=n; i++){
        day = i + map[0][i];
        if(day <= n+1){
            dp[day] = max(dp[day], dp[i]+map[1][i]);
            ans = max(ans, dp[day]);
        }
        
        dp[i+1] = max(dp[i+1], dp[i]);
        ans = max(ans, dp[i+1]);
    }
    
    cout << ans;
}