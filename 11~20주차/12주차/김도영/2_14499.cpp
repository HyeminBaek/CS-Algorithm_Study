#include <iostream>

int const MAX = 21;
using namespace std;

int n, m, k;
int map[MAX][MAX];
int dice[7] = {0};    //[1]이 윗면
pair<int, int> cube;
pair<int, int> movdir[] = {{0,0}, {0,1}, {0, -1}, {-1, 0}, {1, 0}};

void Move_Cube(int dir){
    int temp;

    //오른쪽
    if(dir == 1){
        temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    //왼쪽
    else if(dir == 2){
        temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }
    //위
    else if(dir == 3){
        temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
    //아래
    else if(dir == 4){
        temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }

    return;
}

int main(){
    cin >> n >> m >> cube.first >> cube.second >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int order;
    for(int i=0; i<k; i++){
        cin >> order;

        int ny = cube.first + movdir[order].first;
        int nx = cube.second + movdir[order].second;
        if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

        Move_Cube(order);

        if(map[ny][nx] == 0){
            map[ny][nx] = dice[6];
        }
        else if(map[ny][nx] > 0){
            int temp = map[ny][nx];
            map[ny][nx] = 0;
            dice[6] = temp;
        }

        cube.first = ny;
        cube.second = nx;
        cout << dice[1] << "\n";
    }
}