#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> tree[50001];
int parent[50001];
int depth[50001];

void set(int prev, int now)
{
    for(int i=0;i<tree[now].size();i++)
    {
        if(tree[now][i]==prev)  continue;
        
        depth[tree[now][i]] = depth[now]+1;
        parent[tree[now][i]]=now;
        set(now,tree[now][i]);
    }
}

int findLCA(int u, int v)
{
    while(depth[u]!=depth[v])   v = parent[v];
    while(u!=v)
    {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v;
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    set(0,1);
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>u>>v;
        if(depth[u]>depth[v])   swap(u,v);
        printf("%d\n",findLCA(u,v));
    }
    
    return 0;
}
