#include <iostream>
#include <queue>

const int MAX = 1001;
using namespace std;

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int h, w, sy, sx, ey, ex;

queue<pair<pair<int, int>, int>> q;
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void all_print(int y, int x){
    map[y][x] = 2;

    cout << "\n";
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    map[y][x] = 0;
}

bool Check(int y, int x, int d){
    //오
    if (d == 0){
        int nx = x + w-1;
        if(m < nx) return false;

        for(int i= y; i<y+h; i++){
            if(map[i][nx] == 1)
                return false;
        }
    }
    //왼
    else if(d == 1){
        for(int i=y; i<y+h; i++){
            if(map[i][x] == 1)
                return false;
        }
    }
    //하
    else if (d == 2){
        int ny = y + h-1;
        if(n < ny) return false;
        for(int j=x; j< x+w; j++){
            if(map[ny][j] == 1)
                return false;
        }
    }
    //상
    else if(d == 3){
        for(int j=x; j<x+w; j++){
            if(map[y][j] == 1)
                return false;
        }
    }

    return true;
}

void BFS(){
    while (!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(y == ey && x == ex){
            cout << cnt;
            return;
        }

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny <= 0 || n < ny || nx <= 0 || m < nx) continue;
            if(visit[ny][nx] == false && Check(ny, nx, i) == true){
                visit[ny][nx] = true;
                q.push({{ny, nx}, cnt+1});
            }
        }
    }

    cout << -1;
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    cin >> h >> w >> sy >> sx >> ey >> ex;

    visit[sy][sx] = true;
    q.push({{sy, sx}, 0});
    BFS();
}