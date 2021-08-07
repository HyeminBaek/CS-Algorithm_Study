#include <iostream>

using namespace std;

int n, m, ans = 0;
int map[500][500];
int visit[500][500];
pair<int, int> movdir[] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(int y, int x, int total, int cnt){
    if(cnt == 4){
        ans = max(ans, total);
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + movdir[i].first;
        int nx = x + movdir[i].second;

        if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

        if(visit[ny][nx] == false){
            visit[ny][nx] = true;
            DFS(ny, nx, total+map[ny][nx], cnt+1);
            visit[ny][nx] = false;
        }
    }
}

void Other(int y, int x){
    int temp = 0;

    //ㅗ
    if(0 <= y-1 && 0 <= x-1 && x+1 < m)
        temp = max(temp, map[y][x-1]+map[y][x]+map[y][x+1]+map[y-1][x]);
    
    //ㅜ
    if(y+1 < n && 0 <= x-1 && x+1 < m)
        temp = max(temp, map[y][x-1]+map[y][x]+map[y][x+1]+map[y+1][x]);

    //ㅓ
    if(0 <= y-1 && y+1 < n && 0 <= x-1)
        temp = max(temp, map[y-1][x]+map[y][x]+map[y+1][x]+map[y][x-1]);

    //ㅏ
    if(0 <= y-1 && y+1 < n && x+1 < m)
        temp = max(temp, map[y-1][x]+map[y][x]+map[y+1][x]+map[y][x+1]);
     
    ans = max(ans, temp);
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            Other(i, j);

            visit[i][j] = true;
            DFS(i, j, map[i][j], 1);
            visit[i][j] = false;
        }
    }

    cout << ans;
}