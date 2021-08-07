#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct _CAR{
    int y;
    int x;
    int dir;
    int cost;
}CAR;

int n, Min = 987654321;
bool visit[26][26];
vector<vector<int>> board;
pair<int, int> movdir[] = {{1,0},{-1,0},{0,1},{0,-1}};  // 하, 상, 오, 왼

void BFS(){
    queue<CAR> q;
    q.push({0, 0, 0, 0});
    q.push({0, 0, 2, 0});
    visit[0][0] = true;

    while(!q.empty()){
        CAR car = q.front();
        q.pop();

        if(car.y == n-1 && car.x == n-1){
            Min = min(Min, car.cost);
            continue;
        }

        for(int i=0; i<4; i++){
            int ny = car.y + movdir[i].first;
            int nx = car.x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            if(board[ny][nx] != 1){
                int new_cost = car.cost;
                if(i == car.dir)
                    new_cost += 100;
                else
                    new_cost += 600; //(100+500)

                if(board[ny][nx] == 0 || new_cost <= board[ny][nx]){
                    q.push({ny, nx, i, new_cost});
                    board[ny][nx] = new_cost;
                }
            }
        }
    }
}

#if 0
void BFS(){
    queue<pair<pair<int, int>, string>> q;
    q.push({{0, 0}, ""});
    visit[0][0] = true;

    while(!q.empty()){
        int size = q.size();

        for(int cur=0; cur<size; cur++){
            int y = q.front().first.first;
            int x = q.front().first.second;
            string str = q.front().second;
            q.pop();

            if(y == n-1 && x == n-1){
                int money = cal(str);
                Min = min(Min, money);
            }

            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
                if(board[ny][nx] == 0 && visit[ny][nx] == false){
                    visit[ny][nx] = true;
                    q.push({{ny, nx}, str+to_string(i)});
                }
            }
        }
    }
}
#endif

int solution(vector<vector<int>> b) {
    board = b;
    n = board.size();
    BFS();
    return Min;
}

int main(){
    vector<vector<int>> array = {{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, 
    {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}};
    cout << solution(array);
}