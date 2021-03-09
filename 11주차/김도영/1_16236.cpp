#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

const int MAX = 20;
using namespace std;

typedef struct _SHARK{
    int y;
    int x;
    int size;
    int cnt;
} SHARK;

int n, time = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
SHARK shark;
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// 물고기 데이터를 정렬 -> 행, 열 오름차순
// 물고기 먹기 이 때 지금까지 먹었던 물고기 수를 통해 크기 증가
void EAT(vector<pair<pair<int, int>, int>> fish){
    if(fish.size() > 1){
        sort(fish.begin(), fish.end());
    }

    int y = fish[0].first.first;
    int x = fish[0].first.second;
    map[y][x] = 0;

    shark.y = y; shark.x = x;

    if(++shark.cnt == shark.size){
        shark.size += 1;
        shark.cnt = 0;
    }
}

bool Search(){
    memset(visit, false, sizeof(visit));
    vector<pair<pair<int, int>, int>> fish;
    queue<pair<int, int>> q;
    bool flag = false;

    q.push({shark.y, shark.x});
    visit[shark.y][shark.x] = true;
    
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();

        for(int cur =0; cur <size; cur++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop(); 

            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(visit[ny][nx] == false && map[ny][nx] <= shark.size){
                        visit[ny][nx] = true;
                        q.push({ny, nx});
                        
                        if(0 < map[ny][nx] && map[ny][nx] < shark.size){
                            fish.push_back({{ny, nx}, map[ny][nx]});
                        }
                    }
                }
            }
        }

        cnt++;
        if(!fish.empty()){
            flag = true;
            break;
        }   
    }

    //잡아 먹을 수 있는 물고기가 존재
    //현재 fish 벡터에 들어있는 물고기의 데이터는 아기 상어부터 같은 거리에 있는 물고기들
    if(flag){
        EAT(fish);
        time += cnt;
    }
    
    return flag;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                shark = {i, j, 2, 0};
                map[i][j] = 0;
            }
        }
    }

    while(Search()){}
    cout << time;
}