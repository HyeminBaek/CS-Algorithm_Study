#include <iostream>
#include <queue>

const int MAX = 50;
using namespace std;

int n;
int map[MAX][MAX], memo[MAX][MAX];
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void BFS(){
    fill(memo[0], memo[MAX], 987654321);
    queue<pair<int, int>> q;
    q.push({0, 0});
    memo[0][0] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            
            if(map[ny][nx] == 1){
                if(memo[y][x] < memo[ny][nx]){
                    memo[ny][nx] = memo[y][x];
                    q.push({ny, nx});
                }
            }
            else if(map[ny][nx] == 0){
                if(memo[y][x]+1 < memo[ny][nx]){
                    memo[ny][nx] = memo[y][x]+1;
                    q.push({ny, nx});
                }
            }
        }

    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++){
            map[i][j] = s[j] - '0';
        }
    }

    BFS();
    cout << memo[n-1][n-1];
}