//
//  main.cpp
//  트리의 지름_2
//
//  Created by 오현식 on 2021/01/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> tree[10001];
int dp[10001][2];   // 0:diameter of tree , 1:longest length to leaf of tree

int setLongestLeaf(int prev, int root)
{
    for(int i=0;i<tree[root].size();i++)
    {
        if(tree[root][i].first == prev)     continue;
        
        dp[root][1] = max(dp[root][1], tree[root][i].second + setLongestLeaf(root,tree[root][i].first));
    }
    return dp[root][1];
}

int getDiameter(int prev, int root)
{
    for(int i=0;i<tree[root].size();i++)
    {
        if(tree[root][i].first == prev)   continue;
        
        dp[root][0] = max(dp[root][0], getDiameter(root,tree[root][i].first));
        dp[root][0] = max(dp[root][0], tree[root][i].second + dp[tree[root][i].first][1]);
        
        for(int j=i+1;j<tree[root].size();j++)
        {
            dp[root][0] = max(dp[root][0], tree[root][i].second + tree[root][j].second + dp[tree[root][i].first][1] + dp[tree[root][j].first][1]);
        }
    }
    return dp[root][0];
}

int main(int argc, const char * argv[]) {
    int u, v, w;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v>>w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }
    setLongestLeaf(0,1);
    cout<<getDiameter(0,1);
    return 0;
}
