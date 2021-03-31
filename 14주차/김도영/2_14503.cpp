#include <iostream>

const int MAX = 51;
using namespace std;

typedef struct _ROBOT{
    int y; 
    int x;
    int d;
} ROBOT;

int n, m;
int map[MAX][MAX];
ROBOT robot;
pair<int, int> movdir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};    //0 : 북, 1 : 동, 2 : 남, 3 : 서

int reversed(int d){
    if(d == 0) return 2;
    else if(d == 1) return 3;
    else if(d == 2) return 0;
    return 1;
}

void all_print(){
    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> n >> m;
    cin >> robot.y >> robot.x >> robot.d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];    //0:빈칸 , 1:벽, 2:청소
        }
    }
    
    map[robot.y][robot.x] = 2;    //현재 위치 청소
    int ans = 1;

    while(1){
        //all_print();
        int y = robot.y;
        int x = robot.x;
        int d = robot.d;

        int ty, tx, td, cnt = 0;
        ty = tx = td = -1;
        for(int i=0; i<4; i++){
            d = d-1 < 0 ? 3 : d-1;    //현재 방향에서 반시계로 검사
            int ny = y + movdir[d].first;
            int nx = x + movdir[d].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if(map[ny][nx] != 0){
                cnt++;
            }
            else{
                //반시계 검사하면서 맨 처음 만나는 map[][] == 0 인 정보 저장
                if(ty == -1){
                    ty = ny;
                    tx = nx;
                    td = d;
                    break;
                }
            }
        }
        
        //네 방향이 벽이거나 청소 됨
        if(cnt == 4){
            int nd = reversed(robot.d);
            y += movdir[nd].first;
            x += movdir[nd].second;
            
            if(map[y][x] == 1){    //뒤가 벽이면 중지
                break;
            }
            else{
                robot = {y, x, robot.d};
            }
            continue;
        }
        else{    //네 방향 중 청소할 공간이 있다면
            robot = {ty, tx, td};
        }

        map[robot.y][robot.x] = 2;
        ans++;
    }

    cout << ans;
}