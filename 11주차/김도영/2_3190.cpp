#include <iostream>
#include <vector>
#include <queue>

const int MAX = 100;
using namespace std;

int n, k, l;
int map[MAX][MAX];
vector<pair<int, int>> snake;
queue<pair<int, string>> query;
pair<int, int> movdir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int Rotation(int dir, string s){
    if(s == "D"){
        dir = dir + 1 > 3 ? 0 : dir +1;
    }
    else{
        dir = dir -1 < 0 ? 3 : dir -1;
    }
    return dir;
}

//뱀의 몸에 부딪치거나 격자 밖으로 나가면 return false로 break 시켜줌
bool Move_snake(int dir){
    int head = snake.size()-1;
    int y = snake[head].first;
    int x = snake[head].second;

    int ny = y + movdir[dir].first;
    int nx = x + movdir[dir].second;

    //뱀의 몸에 부딪치거나 격자밖으로 나갔을 때
    if(ny < 0 || n <= ny || nx < 0 || n <= nx) return false;
    if(map[ny][nx] == 1) return false;


    if(map[ny][nx] == 0){
        //꼬리 없애주기
        int tail_y = snake[0].first;
        int tail_x = snake[0].second;
        map[tail_y][tail_x] = 0;

        snake.erase(snake.begin());
    }   
    snake.push_back({ny, nx});
    map[ny][nx] = 1;


    return true;
}

//0 : 빈칸 , 1: 뱀의 위치, 2 : 사과
int main(){
    cin >> n >> k;
    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        map[a-1][b-1] = 2;
    }

    map[0][0] = 1;
    snake.push_back({0, 0});

    cin >> l;
    int x; string c;
    for(int i=0; i<l; i++){
        cin >> x >> c;
        query.push({x, c});
    }

    int time = 0;
    int dir = 0;
    while(1){
        time++;
        if(Move_snake(dir) == false){
            break;
        }

        if(!query.empty()){
            if(time == query.front().first){
                dir = Rotation(dir, query.front().second);
                query.pop();
            }
        }

    }
    cout << time;
}