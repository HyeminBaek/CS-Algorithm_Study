#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> arr;
int dp[10100];

int solve(int idx){
    if(idx==n) return 0;
    if(dp[idx]!=-1) return dp[idx];

    dp[idx] = (int)1e9;
    pair<int,int> here = arr[idx];
    int x = here.first;
    int h = here.second;

    for(int next=idx;next<n;next++){
        pair<int,int> nextinfo = arr[next];
        int nx = nextinfo.first;
        h= max(h,nextinfo.second);

        int cost = max(nx-x,h);
        dp[idx]= min(dp[idx],cost + solve(next+1));    
    }

    return dp[idx];

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;    
        arr.push_back({a,abs(b)*2});
    }    
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++) dp[i]=-1;

    cout<<solve(0)<<'\n';
    

}

