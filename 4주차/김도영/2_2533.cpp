#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[1000001];
int dp[1000001][2]; 

int find(int prev, int now, int isEarly){
    if(dp[now][isEarly] != 0)
        return dp[now][isEarly];

    if(isEarly){
        //prev Early라서 1 추가
        dp[now][1] += 1;
        
        for(int i=0; i<tree[now].size(); i++){
            if(tree[now][i] == prev) continue;
            dp[now][1] += min(find(now, tree[now][i], 0), find(now, tree[now][i], 1));
        }
    }

    else{
        for(int i=0; i<tree[now].size(); i++){
            if(tree[now][i] == prev) continue;
            dp[now][0] += find(now, tree[now][i], 1);
        }
    }

    return dp[now][isEarly];
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << min(find(0, 1, 0), find(0, 1, 1));
}