#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int sequence[10001];    // idx: 1~10,000

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++)   cin>>sequence[i];
    int answer=0;
    int first=1, last=1;
    int sum=sequence[1];
    while(first<=N && last<=N){
        if(sum==M)  answer++;
            
        if(sum<M)   sum += sequence[++last];
        else if(sum>=M) sum -= sequence[first++];
    }
    cout<<answer;
    return 0;
}
