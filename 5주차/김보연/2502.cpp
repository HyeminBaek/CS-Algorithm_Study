#include <iostream>
using namespace std;

int dp[30][2];
int main()
{
    int d,k;
    cin>>d>>k;

    dp[0][0]=1;
    dp[1][1]=1;
    for(int i=2; i<d; i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][0];
        dp[i][1]=dp[i-1][1]+dp[i-2][1];
    }

    int x=1;
    int y=1;
    while(1){
        y = k - x*(dp[d-1][0]);
        //나누어 떨어지면
        if(! (y % dp[d-1][1]))
        {
            y=y/dp[d-1][1];
            break;
        }
        x++;
    }
    cout<<x<<"\n"<<y;
    return 0;
}
