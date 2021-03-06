#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int>   Pos;
typedef pair<int,int>   Rotation;

int N, K, L;
int board[101][101];
int dx[4] = {0,-1,0,1}; // East->North->West->South  :순차적으로 반시계 방향 90도 회전 방향
int dy[4] = {1,0,-1,0};

struct Snake{
    queue<Pos>  body;
    queue<Rotation> informationOfRotation;
    int dir;
    int time;
    
    Snake():dir(0),time(0){
        body.push(Pos(1,1));
    }
    bool move(void){
        time++;
        Pos head = body.back();
        Pos next = Pos(head.first+dx[dir],head.second+dy[dir]);
        if(isOutOfBound(next) || isBody(next))    return false;
        body.push(next);
        if(board[next.first][next.second]==1)   board[next.first][next.second] = 0;
        else    body.pop();
        setDir();
        return true;
    }
    void setRotation(Rotation rotation){
        informationOfRotation.push(rotation);
    }
    void setDir(void){
        Rotation rotation = informationOfRotation.front();
        if(time==rotation.first){
            dir = dir+rotation.second;
            if(dir<0)   dir = (dir+4);
            dir %= 4;
            informationOfRotation.pop();
        }
    }
    bool isOutOfBound(Pos pos){
        if(pos.first<1 || pos.first>N || pos.second<1 || pos.second>N)  return true;
        return false;
    }
    bool isBody(Pos pos){
        queue<Pos> copyOfBody = body;
        while(!copyOfBody.empty()){
            if(copyOfBody.front()==pos) return true;
            copyOfBody.pop();
        }
        return false;
    }
    int getTime(void){
        return time;
    }
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int row, col;
    int sec;
    char dir;
    Snake snake;
    cin>>N>>K;
    for(int i=1;i<=K;i++){
        cin>>row>>col;
        board[row][col] = 1;
    }
    cin>>L;
    for(int i=1;i<=L;i++){
        cin>>sec>>dir;
        if(dir=='L')    snake.setRotation(Rotation(sec,1));
        else    snake.setRotation(Rotation(sec,-1));
    }
    while(snake.move()){}
    cout<<snake.getTime();
    return 0;
}
