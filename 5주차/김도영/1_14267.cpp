#include <iostream>
#include <vector>

const int MAX = 100001;
using namespace std;

int n, m;
vector<int> tree[MAX];
int ret[MAX];

void DFS(int node){

    for(int i=0; i<tree[node].size(); i++){
        int next = tree[node][i];
        ret[next] += ret[node];

        DFS(next);
    }
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int parent; cin >> parent;
        tree[parent].push_back(i);
    }

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        ret[a] += b;
    }

    DFS(1, 0);
    for(int i=1; i<=n; i++){
        cout << ret[i] << " ";
    }
}