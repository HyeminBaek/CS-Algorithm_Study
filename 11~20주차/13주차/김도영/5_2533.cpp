#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[1000001];
int dp[1000001][2];

int find(int prev, int now, int Early){
    if(dp[now][Early] != 0) return dp[now][Early];

    if(Early == 1){
        dp[now][Early] += 1;

        //현재 노드가 얼리어답터라면 그 자식들은 얼리어답터이거나 아니어도 된다.
        for(int i=0; i<v[now].size(); i++){
            if(v[now][i] == prev) continue;
            dp[now][Early] += min(find(now, v[now][i], 0), find(now, v[now][i], 1));
        }
    }
    else{
        //현재 노드가 얼리어답터가 아니라면 그 자식들은 얼리어답터이어야한다.
        for(int i=0; i<v[now].size(); i++){
            if(v[now][i] == prev) continue;
            dp[now][Early] += find(now, v[now][i], 1);
        }
    }

    return dp[now][Early];
}

int main(){
    cin >> n;

    int a, b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << min(find(0, 1, 0), find(0, 1, 1));
}