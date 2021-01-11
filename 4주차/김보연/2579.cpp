#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[300];

int main(){
    int n;
    cin>>n;

    vector<int> score(n,0);
    for(int i=0; i<n; i++)
        cin>>score[i];

    dp[0] = score[0];
    dp[1] = score[0]+score[1];
    dp[2] = max(score[0],score[1])+score[2];
    for(int i=3; i<n; i++)
        dp[i] = max(dp[i-2], dp[i-3]+score[i-1])+score[i];
        
    cout<<dp[n-1];
    return 0;
}
