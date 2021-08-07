#include <iostream>
#include <vector>
#include <queue>

const int MAX = 501;
using namespace std;

int n;
int cost[MAX], indegree[MAX];
int ans[MAX];
vector<int> v[MAX];

int main(){
    cin >> n;
    int pre;
    for(int i=1; i<=n; i++){
        cin >> cost[i];

        while(1){
            cin >> pre;
            if(pre == -1)
                break;

            v[pre].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            ans[i] = cost[i];
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            indegree[next]--;

            ans[next] = max(ans[next], ans[node]+cost[next]);
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}