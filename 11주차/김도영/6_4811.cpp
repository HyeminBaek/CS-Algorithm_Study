#include <iostream>

using namespace std;

long long dp[31][31];

long long dfs(int W, int H){
    if(dp[W][H]) return dp[W][H];

    if(W == 0)
        return 1;
    
    dp[W][H] = dfs(W-1, H+1);
    if(H>0){
        dp[W][H] += dfs(W, H-1);
    }

    return dp[W][H];
}

int main(){
    int tc;
    while(cin >> tc){
        if(tc == 0) break;

        cout << dfs(tc, 0) << "\n";
    }
}