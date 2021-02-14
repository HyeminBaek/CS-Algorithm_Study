#include <iostream>
#include <vector>
#include <cmath>

const int Level = 18;
const int MAX = 1024;
using namespace std;

int depth[MAX];
int ac[MAX][20];
int arr_tree[MAX];

void Make_tree(int cur, int parent){
    depth[cur] = depth[parent]+1;
    ac[cur][0] = parent;

    for(int i=1; i<=Level; i++){
        int temp = ac[cur][i-1];
        ac[cur][i] = ac[temp][i-1];
    }

    if(cur < 512){
        Make_tree(arr_tree[cur*2], cur);
        Make_tree(arr_tree[cur*2+1], cur);
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    
    for(int i=0; i<MAX; i++){
        arr_tree[i] = i;
    }

    depth[0] = -1;
    Make_tree(1, 0);

    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;

        if(depth[x] != depth[y]){
            if(depth[x] > depth[y])
                swap(x, y);

            for(int i=Level; i>=0; i--){
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

        cout << lca*10 << "\n";
    }
}