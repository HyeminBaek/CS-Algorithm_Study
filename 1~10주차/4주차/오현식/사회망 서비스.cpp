#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> tree[1000001];  //  1~1000000
int dp[1000001][2];    // 1~1000000 [1]: , [2]: 0: late adopter, 1: early adopter

int find(int prev, int now, int isEarly)
{
    if(dp[now][isEarly]!=0) return dp[now][isEarly];
    
    if(isEarly==0)
    {
        for(int i=0;i<tree[now].size();i++)
        {
            if(tree[now][i]==prev)  continue;
            dp[now][0] += find(now,tree[now][i],1);
        }
    }
    else
    {
        dp[now][1]+=1;
        for(int i=0;i<tree[now].size();i++)
        {
            if(tree[now][i]==prev)  continue;
            dp[now][1] += min(find(now,tree[now][i],0), find(now,tree[now][i],1));
        }
    }
    return dp[now][isEarly];
}

int main(int argc, const char * argv[]) {
    int u, v;
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout<<min(find(0,1,0),find(0,1,1));
    return 0;
}
