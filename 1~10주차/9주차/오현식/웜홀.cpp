#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int,int> edge;

int TC, N, M, W;
int D[501]; // idx: 1~500
bool visited[501];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v, c;
    cin>>TC;
    while(TC--){
        fill(&visited[0],&visited[501],false);
        bool isYes=false;
        vector<edge> graph[501]; // idx: 1~500
        cin>>N>>M>>W;
        for(int i=0;i<M;i++){
            cin>>u>>v>>c;
            graph[u].push_back(edge(v,c));
            graph[v].push_back(edge(u,c));
        }
        for(int i=0;i<W;i++){
            cin>>u>>v>>c;
            graph[u].push_back(edge(v,-c));
        }
        while(true){
            fill(&D[0],&D[501],INT_MAX);
            bool isComponent=false;
            for(int i=1;i<=N;i++){
                if(!visited[i]){
                    visited[i]=true;
                    D[i]=0;
                    isComponent=true;
                    break;
                }
            }
            if(!isComponent)    break;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    for(int k=0;k<graph[j].size();k++){
                        int u = j;
                        int v = graph[j][k].first;
                        int cost = graph[j][k].second;
                        if(D[u]!=INT_MAX && D[u]+cost<D[v]){
                            if(i==N)    isYes=true;
                            visited[v] = true;
                            D[v] = D[u] + cost;
                        }
                    }
                }
            }
        }
        if(isYes)   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}
