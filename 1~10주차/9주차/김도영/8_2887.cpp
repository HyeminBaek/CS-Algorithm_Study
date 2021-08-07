#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 100000;
using namespace std;

int n;
vector<pair<int, int>> X, Y, Z;
vector<pair<int, pair<int, int>>> dist;
int parent[MAX];

int Find(int x){
    if(parent[x] == x){
        return x;
    }
    
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

//최소 스패닝 트리
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y, z; cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
        parent[i] = i;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for(int i=0; i<n-1; i++){
        dist.push_back({X[i+1].first - X[i].first, {X[i+1].second, X[i].second}});
        dist.push_back({Y[i+1].first - Y[i].first, {Y[i+1].second, Y[i].second}});
        dist.push_back({Z[i+1].first - Z[i].first, {Z[i+1].second, Z[i].second}});
    }
    
    sort(dist.begin(), dist.end());
    int ret = 0;
    for(int i=0; i<dist.size(); i++){
        int cost = dist[i].first;
        int node1 = dist[i].second.first;
        int node2 = dist[i].second.second;

        if(Find(node1) != Find(node2)){
            Union(node1, node2);
            ret += cost;
        }
    }
    cout << ret;
}