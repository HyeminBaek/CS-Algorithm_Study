#include <iostream>

using namespace std;

int n, k;
int dp[101][100001];
pair<int, int> arr[101];

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i].first <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].first]+arr[i].second);
            }
        }
    }


    cout << dp[n][k];
}