#include <iostream>

using namespace std;

int d, n;
int dp[100];
bool flag = true;

void DFS(int idx){
    if(idx == 1){
        flag = false;
        return;
    }
    
    int b = dp[idx];
    int a = dp[idx+1] - b;
    if(a <= b){
        dp[idx-1] = a;
        DFS(idx-1);
    }
}

int main(){
    cin >> d >> n;

    dp[d] = n;
    int rice_cake = (n+1)/2;
    for(; rice_cake<=n && flag; rice_cake++){
        dp[d-1] = rice_cake;
        DFS(d-1);
    }

    cout << dp[1] << "\n" << dp[2];
}