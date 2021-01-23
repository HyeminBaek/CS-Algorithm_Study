//
//  main.cpp
//  트리의 지름
//
//  Created by 오현식 on 2021/01/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> tree[10001];  // node, weight
int diameterOfTree;

void wander(int prev, int now, int length)  //  length : distance of [startNode ~ now]
{
    if(tree[now].size()==1)   diameterOfTree = max(diameterOfTree, length);
    for(int i=0;i<tree[now].size();i++)
    {
        if(tree[now][i].first==prev)  continue;
        wander(now, tree[now][i].first, length + tree[now][i].second);
    }
}

int main(int argc, const char * argv[]) {
    int u, v, w;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v>>w;
        tree[u].push_back(make_pair(v,w));
        tree[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=n;i++)
    {
        if(tree[i].size()==1)   wander(0,i,0);
    }
    cout<<diameterOfTree;
    return 0;
}
