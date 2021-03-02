#include <iostream>

using namespace std;

int n;
int array[100000];
int dp[100000][2];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    int ans = array[0];
    dp[0][0] = array[0];
    dp[0][1] = array[0];
    for(int i=1; i<n; i++){
        dp[i][0] = max(array[i], dp[i-1][0]+array[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+array[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
}