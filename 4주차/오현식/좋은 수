#include <iostream>

using namespace std;

int N;
int sequence[5001];
bool dp[400001]; // 0: -200,000 , 400,000: +200,000

int main(int argc, const char * argv[]) {
    cin>>N;
    int cntOfGoodNumber=0;
    for(int i=1;i<=N;i++)   cin>>sequence[i];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(dp[sequence[i]-sequence[j]+200000]){
                cntOfGoodNumber++;
                break;
            }
        }
        for(int j=1;j<=i;j++)   dp[sequence[j]+sequence[i]+200000] = true;
    }
    cout<<cntOfGoodNumber;
    return 0;
}
