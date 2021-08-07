#include <iostream>
#include <cstring>
#include <queue>

const int MAX = 8;
using namespace std;

int n, m, ans = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void Spread(){
    int temp[MAX][MAX];
    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            temp[i][j] = map[i][j];
            if(map[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if(temp[ny][nx] == 0){
                temp[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(temp[i][j] == 0){
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

void DFS(int wall){
    if(wall == 3){
        Spread();    //바이러스 퍼뜨리기
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                DFS(wall+1);
                map[i][j] = 0;
            }
        }
    }
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
            if(map[i][j] == 0){

                map[i][j] = 1;
                DFS(1);
                map[i][j] = 0;
            }
        }
    }

    cout << ans;
}