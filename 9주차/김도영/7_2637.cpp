#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MAX = 101;
using namespace std;

int n, m;
vector<pair<int, int>> graph[MAX];
int Indegree[MAX];
int weight[MAX];
vector<int> ans;

void BFS(int root){
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(graph[cur].size() == 0){
            ans.push_back(cur);
            continue;
        }

        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;
            weight[next] += weight[cur] * cost;

            Indegree[next]--;
            if(Indegree[next] == 0)
                q.push(next);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, k; cin >> x >> y >> k;
        graph[x].push_back({y, k});
        Indegree[y]++;
    }

    weight[n] = 1;
    BFS(n);

    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " " << weight[ans[i]] << "\n";
    }
}