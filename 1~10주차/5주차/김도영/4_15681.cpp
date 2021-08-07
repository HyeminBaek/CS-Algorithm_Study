#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, root, q;
vector<int> graph[100001];
bool visit[100001];
int count[100001];

int DFS(int node){
    if(count[node] != 0){
        return count[node];
    }

    int cnt = 1;
    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if(visit[next] == false){
            visit[next] = true;
            cnt += DFS(next);
        }
    }

    count[node] = cnt;
    return count[node];
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    
    cin >> n >> root >> q;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visit[root] = true;
    count[root] = DFS(root);

    for(int i=0; i<q; i++){
        int node; cin >> node;
        cout << count[node] << "\n";
    }
}