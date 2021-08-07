#include <iostream>
#include <climits>

using namespace std;

int n, m;
int D[101][101];    // idx: 1~100

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v, c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)   D[i][j] = i==j ? 0 : INT_MAX ;
    }
    for(int i=0;i<m;i++){
        cin>>u>>v>>c;
        D[u][v] = min(D[u][v],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)   D[i][j] = D[i][k]+D[k][j]<0 ? D[i][j] : min(D[i][j], D[i][k]+D[k][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(D[i][j]==INT_MAX)    cout<<0<<" ";
            else    cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
