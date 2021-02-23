#include <iostream>
#include <queue>

const int MAX = 100;
const int INF = 1e9;
using namespace std;

int n, m;
int map[MAX][MAX], Dist[MAX][MAX];
priority_queue<pair<int, int>> q;
pair<int, int> movdir[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j]-'0';
            Dist[i][j] = INF;
        }
    }

    q.push({0, 0});
    Dist[0][0] = 0;
    while(!q.empty()){
        int y = q.top().first;
        int x = q.top().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

            if(Dist[y][x]+map[ny][nx] < Dist[ny][nx]){
                Dist[ny][nx] = Dist[y][x]+map[ny][nx];
                q.push({ny, nx});
            }
        }
    }

    cout << Dist[n-1][m-1];
    return 0;
}