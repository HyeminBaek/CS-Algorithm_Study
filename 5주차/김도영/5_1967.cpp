#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, Max = 0, point = 0;
vector<pair<int, int>> v[10001];
bool visit[10001];

void DFS(int node, int len){
    if(visit[node]) return;

    visit[node] = true;
    if(Max < len){
        Max = len;
        point = node;
    }
    
    for(int i=0; i<v[node].size(); i++){
        DFS(v[node][i].first, len+v[node][i].second);
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;   
        
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    DFS(1, 0);

    Max = 0;
    memset(visit, false, sizeof(visit));
    DFS(point, 0);

    cout << Max;
}