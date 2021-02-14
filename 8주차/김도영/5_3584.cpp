#include <iostream>
#include <vector>
#include <cstring>

const int level = 18;
const int MAX = 100001;
using namespace std;

int n;
int depth[MAX];
int ac[MAX][20];
int parent[MAX];
vector<int> graph[MAX];

void Make_Tree(int cur, int parent){
    depth[cur] = depth[parent]+1;    //깊이 설정
    
    ac[cur][0] = parent;             //조상 설정
    for(int i=1; i<=level; i++){
        int temp = ac[cur][i-1];
        ac[cur][i] = ac[temp][i-1];
    }

    for(int i=0; i<graph[cur].size(); i++){
        int child = graph[cur][i];
        if(child != parent){
            Make_Tree(child, cur);
        }
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T; cin >> T;

    while(T--){
        memset(parent, 0, sizeof(parent));
        memset(depth, 0, sizeof(depth));
        memset(ac, 0, sizeof(ac));
        for(int i=0; i<MAX; i++){
            graph[i].clear();
        }

        cin >> n;
        for(int i=0; i<n-1; i++){
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);

            parent[v] = u;
        }

        int root;
        for(int i=1; i<=n; i++){
            if(parent[i] == 0){
                root = i;
                break;
            }
        }

        depth[0] = -1;
        Make_Tree(root, 0);

        int u, v; cin >> u >> v;

        //깊이가 다르면 맞춰주는 처리가 필요
        if(depth[u] != depth[v]){
            if(depth[u] > depth[v]){
                swap(u, v);
            }
            
            for(int i=level; i>=0; i--){
                if(depth[u] <= depth[ac[v][i]]){
                    v = ac[v][i];
                }
            }
        }

        int lca = u;
        if(u != v){
            for(int i=level; i>=0; i--){
                if(ac[u][i] != ac[v][i]){
                    u = ac[u][i];
                    v = ac[v][i];
                }
                lca = ac[u][i];
            }
        }
        cout << lca <<"\n";
    }
}