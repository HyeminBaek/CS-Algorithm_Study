#include <iostream>

const int MAX = 16;
using namespace std;

int n,m,k;
int dp[MAX][MAX] = {0};

void all_print(){
    cout << "\n";
    for(int i=1; i<=MAX; i++){
        for(int j=1; j<=MAX; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

void calculation(int sy, int sx, int ey, int ex){
    for(int i=sy; i<=ey; i++){
        for(int j=sx; j<=ex; j++){
            if(dp[i-1][j] == 0 && dp[i][j-1] == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
}

int main(){
    cin >> n >> m >> k;
    if(k == 0){
        calculation(1, 1, n, m);
    }
    else{
        int y, x;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(k == 1){
                    y = i, x = j;
                }
                k--;
            }
        }

        calculation(1, 1, y, x);
        all_print();
        calculation(y, x, n, m);
        all_print();
    }
    cout << dp[n][m];
    return 0;
}