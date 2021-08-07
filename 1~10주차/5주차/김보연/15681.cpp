#include <iostream>
#include <vector>

using namespace std;

vector<int> input[100001];
int visited[100001];
int count[100001];

void dfs(int u){
    count[u]=1;
    visited[u]=1;
    
    for(int v:input[u])
    {
        if(!visited[v]) {
            dfs(v);
            count[u]+=count[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,r,q;

    cin>>n>>r>>q;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        input[u].push_back(v);
        input[v].push_back(u);
    }
    
    dfs(r);
    for(int i=0; i<q; i++){
        int qq;
        cin>>qq;
        if(qq==r) cout<<n<<"\n";
        else cout<<count[qq]<<"\n";
    }

    return 0;
}
