#include <iostream>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int,int> Pos;

int C, R;
int map[101][101];  // idx: 1~100
int cost[101][101]; //idx: 1~100
int dx[4] = {0,0,1,-1}; //E W S N
int dy[4] = {1,-1,0,0};

int dijkstra(void){
    cost[1][1] = 0;
    priority_queue<pair<int,Pos>> pq;
    pq.push(make_pair(-cost[1][1],Pos(1,1)));
    while(!pq.empty()){
        int currentCost = -pq.top().first;
        Pos currentPos = pq.top().second;
        pq.pop();
        if(cost[currentPos.first][currentPos.second]<currentCost)   continue;
        
        for(int i=0;i<4;i++){
            int next_x = currentPos.first + dx[i];
            int next_y = currentPos.second + dy[i];
            if(next_x<1 || next_x>R || next_y<1 || next_y>C)    continue;
            int next_cost = map[next_x][next_y]==1 ? 1 : 0 ;
            if(currentCost + next_cost < cost[next_x][next_y]){
                cost[next_x][next_y] = currentCost + next_cost;
                pq.push(make_pair(-cost[next_x][next_y], Pos(next_x,next_y)));
            }
            
        }
    }
    return cost[R][C];
}

int main(int argc, const char * argv[]) {
    string line;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>C>>R;
    for(int i=1;i<=R;i++){
        cin>>line;
        for(int j=1;j<=C;j++){
            map[i][j] = line[j-1]-'0';
            cost[i][j]=INT_MAX;
        }
    }
    cout<<dijkstra();
    return 0;
}
