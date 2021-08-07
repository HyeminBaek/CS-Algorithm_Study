#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int,int>

vector<pii> input[10001];
int visited[10001];
int max_weight,idx;

void init()
{
    for(int i=0; i<10001; i++)
        visited[i]=0;
}

void dfs(int st, int weight){
    visited[st]=1;

    if(weight > max_weight){
        max_weight = weight;
        idx = st;
    }
    for(pii next: input[st])
    {
        if(!visited[next.first])
            dfs(next.first, weight+next.second);
    }
}

int main()
{
    int n=0;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        input[u].push_back({v,w});
        input[v].push_back({u,w});
    }
    //루트에서 가장 먼 점 찾기 -> idx 
    dfs(1,0);
    init();
    //idx 에서 가장 먼 정점 찾기
    dfs(idx,0);
    cout<<max_weight;
    
    return 0;
}
