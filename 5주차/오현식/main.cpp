//
//  main.cpp
//  트리와 쿼리
//
//  Created by 오현식 on 2021/01/21.
//

#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<int> tree[100001];
int dp[100001]; // dp[a] a번 노드를 루트로 하는 서브트리의 노드의 갯수
bool visited[100001];

int getNumOfNodes(int root)
{
    if(dp[root]!=0) return dp[root];
    
    dp[root]+=1;
    for(int i=0;i<tree[root].size();i++)
    {
        if(visited[tree[root][i]])  continue;
        
        visited[tree[root][i]] = true;
        dp[root] += getNumOfNodes(tree[root][i]);
    }
    return dp[root];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v;
    int root;
    cin>>N>>R>>Q;
    for(int i=0;i<N-1;i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    visited[R] = true;
    dp[R] = getNumOfNodes(R);
    for(int i=0;i<Q;i++)
    {
        cin>>root;
        cout<<dp[root]<<'\n';
    }
    return 0;
}
