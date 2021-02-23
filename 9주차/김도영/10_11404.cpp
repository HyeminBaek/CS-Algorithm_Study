#include <iostream>
#include <vector>

const int MAX = 101;
const int INF = 1e9;
using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> edge;
int Dist[MAX][MAX];

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                Dist[i][j] = 0;
                continue;
            }
            Dist[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        Dist[a][b] = min(Dist[a][b], c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                Dist[i][j] = min(Dist[i][j], Dist[i][k]+Dist[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(Dist[i][j] == INF){
                Dist[i][j] = 0;
            }
            cout << Dist[i][j] << " ";
        }
        cout << "\n";
    }
}