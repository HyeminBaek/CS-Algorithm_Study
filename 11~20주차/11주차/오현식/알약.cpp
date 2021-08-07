#include <iostream>
#include <cstring>

using namespace std;

int N;
long long dp[31][31]; // idx: 1~30

long long getNumOfCases(int numOfPill, int numOfHalf){
    if(numOfPill<0 || numOfHalf<0)  return 0;
    if(numOfPill==0 && numOfHalf==1)    return 1;
    if(dp[numOfPill][numOfHalf]!=0)    return dp[numOfPill][numOfHalf];
    
    dp[numOfPill][numOfHalf] = getNumOfCases(numOfPill-1, numOfHalf+1) + getNumOfCases(numOfPill, numOfHalf-1);
    return dp[numOfPill][numOfHalf];
}

int main(int argc, const char * argv[]) {
    while(true){
        cin>>N;
        if(N==0)    break;
        cout<<getNumOfCases(N,0)<<endl;
    }
    return 0;
}
