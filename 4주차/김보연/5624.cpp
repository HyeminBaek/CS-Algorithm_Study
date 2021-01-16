#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dp[400001];
vector<int> input(n,0);
int n,ans;

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>input[i];
    
    for(int i=0;i<n; i++){
        for(int j=0; j<i; j++){
            if(dp[input[i]-input[j]+200000]){
                ans++;
                break;
            }
        }
       for(int j=0; j<=i; j++)
            dp[input[i]-input[j]+200000]++;
    }
    cout<<ans;
    return 0;
}

//시간 초과 n^3
int main2(){
    cin>>n;
    set<int> s1,s2,s3;
    
    for(int i=0; i<n; i++)
        cin>>input[i];
    
    for(int i=0;i<n; i++){
        s1.insert(input[i]);
        for(int j=0; j<i; j++){
            for(auto i:s1)
                s2.insert(i+input[j]);
            for(auto i:s2)
                s3.insert(i+input[j]);
        }
        if(s3.count(input[i])>0) ans++;
    }
    cout<<ans;
    return 0;
}
