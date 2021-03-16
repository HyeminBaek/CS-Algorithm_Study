#include <iostream>

const int n = 4;
using namespace std;

typedef struct _FISH{
    int y;
    int x;
    int dir;
    bool live;
} FISH;

int ans = 0;
int map[4][4];
FISH fish[17] = {0};
pair<int, int> movdir[] = {{0,0}, {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

int Rotation(int dir){
    return dir+1 > 8 ? 1 : dir+1; 
}

void Swap(int idx1, int idx2){
    FISH temp = fish[idx1];
    fish[idx1].y = fish[idx2].y;
    fish[idx1].x = fish[idx2].x;

    fish[idx2].y = temp.y;
    fish[idx2].x = temp.x;
}

void Move_Fish(){
    for(int i=1; i<17; i++){
        if(fish[i].live == false) continue;

        int y = fish[i].y;
        int x = fish[i].x;
        int dir = fish[i].dir;

        int ny = y + movdir[dir].first;
        int nx = x + movdir[dir].second;
        bool flag = false;
        
        if(0 <= ny && ny < n && 0 <= nx && nx < n){
            if(map[ny][nx] == 0){
                flag = true;
                fish[i].y = ny;
                fish[i].x = nx;
                map[ny][nx] = i;
                map[y][x] = 0;
            }
            else if(map[ny][nx] != -1){
                flag = true;
                Swap(i, map[ny][nx]);
                map[y][x] = map[ny][nx];
                map[ny][nx] = i;
            }
        }

        if(flag == false){
            int ndir = Rotation(dir);
            int ny = y + movdir[ndir].first;
            int nx = x + movdir[ndir].second;

            while(ndir != dir){
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(map[ny][nx] == 0){
                        fish[i].y = ny;
                        fish[i].x = nx;
                        fish[i].dir = ndir;

                        map[ny][nx] = i;
                        map[y][x] = 0;
                        break;
                    }
                    else if(map[ny][nx] != -1){
                        Swap(i, map[ny][nx]);
                        fish[i].dir = ndir;

                        map[y][x] = map[ny][nx];
                        map[ny][nx] = i;
                        break;
                    }
                }
                
                ndir = Rotation(ndir);
                ny = y + movdir[ndir].first;
                nx = x + movdir[ndir].second;
            }
        }
    }
}

void Copy(int a[4][4], FISH b[17], int in_a[4][4], FISH in_b[17]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = in_a[i][j];
        }
    }

    for(int i=1; i<17; i++){
        b[i] = in_b[i];
    }
}

void Change_state(int y, int x, int ny, int nx, int idx, bool flag){
    if(flag){
        map[y][x] = 0;
        map[ny][nx] = -1;
        fish[idx].live = false;
    }
    else{
        map[y][x] = -1;
        map[ny][nx] = idx;
        fish[idx].live = true;
    }
}

void DFS(int shark_y, int shark_x, int shark_dir, int eat){
    ans = max(ans, eat);

    int t_map[4][4];
    FISH t_fish[17] = {0};
    Copy(t_map, t_fish, map, fish);

    Move_Fish();

    for(int i=1; i<n; i++){
        int ny = shark_y + (movdir[shark_dir].first * i);
        int nx = shark_x + (movdir[shark_dir].second * i);

        if(0 <= ny && ny < n && 0 <= nx && nx < n){
            if(map[ny][nx] == 0) continue;

            int num = map[ny][nx];
            int ndir = fish[num].dir;

            Change_state(shark_y, shark_x, ny, nx, num, true);
            DFS(ny, nx, ndir, eat+num);
            Change_state(shark_y, shark_x, ny, nx, num, false);
        }

        else break;
    }
    Copy(map, fish, t_map, t_fish);
}

// 상어 : -1, 빈 칸 : 0, 물고기 : 1 ~ 16
int main(){
    int a, b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a >> b;
            fish[a] = {i, j, b, true};
            map[i][j] = a;
        }
    }

    int num = map[0][0];
    int dir = fish[num].dir;
    fish[num].live = false;
    map[0][0] = -1;

    DFS(0, 0, dir, num);
    cout << ans;
}