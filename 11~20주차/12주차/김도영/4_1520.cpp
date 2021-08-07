#include <iostream>

const int MAX = 500;
using namespace std;

int n, m, ans;
int map[MAX][MAX], dp[MAX][MAX];
pair<int, int> movdir[] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

int DFS(int y, int x){
    if(y == n-1 && x == m-1) return 1;
    if(dp[y][x] != -1) return dp[y][x];
    
    dp[y][x] = 0;
    for(int i=0; i<4; i++){
        int ny = y + movdir[i].first;
        int nx = x + movdir[i].second;

        if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if(map[ny][nx] < map[y][x]){
            dp[y][x] += DFS(ny, nx);
        }
    }

    return dp[y][x];
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    } 

    cout << DFS(0, 0);
}