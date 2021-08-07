#include <iostream>
#include <vector>

const int Level = 18;
const int MAX = 50001;
using namespace std;

int n;
int depth[MAX];
int ac[MAX][20];
vector<int> graph[MAX];

void Make_Tree(int cur, int parent){
    depth[cur] = depth[parent]+1;
    ac[cur][0] = parent;

    for(int i=1; i<=Level; i++){
        int pp = ac[cur][i-1];
        ac[cur][i] = ac[pp][i-1];
    }

    for(int i=0; i<graph[cur].size(); i++){
        int child = graph[cur][i];
        if(child != parent){
            Make_Tree(child, cur);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    depth[0] = -1;
    Make_Tree(1, 0);

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;

        if(depth[x] != depth[y]){
            if(depth[x] > depth[y]){
                swap(x, y);
            }

            for(int i = Level; i>=0; i--){
                if(depth[x] <= depth[ac[y][i]]){
                    y = ac[y][i];
                }
            }
        }

        int lca = x;
        if(x != y){
            for(int i=Level; i>=0; i--){
                if(ac[x][i] != ac[y][i]){
                    x = ac[x][i];
                    y = ac[y][i];
                }
                lca = ac[x][i];
            }
        }

        cout << lca << "\n";
    }
}