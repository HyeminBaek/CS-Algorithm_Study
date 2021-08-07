#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int>   Pos;

int n;
int board[51][51];
int dist[51][51];
bool visited[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isOutOfBound(Pos pos){
    if(pos.first<1 || pos.first>n || pos.second<1 || pos.second>n)  return true;
    return false;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string line;
    cin>>n;
    fill(&dist[1][1],&dist[n][n]+1,INT_MAX);
    for(int i=1;i<=n;i++){
        cin>>line;
        for(int j=1;j<=n;j++){
            board[i][j] = line[j-1]-'0';
        }
    }
    priority_queue<pair<int,Pos>>   pq;
    dist[1][1]=0;
    pq.push({-dist[1][1],Pos(1,1)});
    while(!pq.empty()){
        int currentDist = -pq.top().first;
        Pos currentPos = pq.top().second;
        pq.pop();
        if(visited[currentPos.first][currentPos.second])    continue;;
        if(currentPos == Pos(n,n)){
            cout<<currentDist;
            break;
        }
        
        visited[currentPos.first][currentPos.second]=true;
        for(int i=0;i<4;i++){
            Pos nextPos = Pos(currentPos.first+dx[i],currentPos.second+dy[i]);
            int nextCost = board[nextPos.first][nextPos.second]==0 ? 1 : 0;
            if(isOutOfBound(nextPos))    continue;
            if(dist[currentPos.first][currentPos.second]+nextCost < dist[nextPos.first][nextPos.second]){
                dist[nextPos.first][nextPos.second] = dist[currentPos.first][currentPos.second]+nextCost;
                pq.push({-dist[nextPos.first][nextPos.second],nextPos});
            }
        }
    }
    return 0;
}
