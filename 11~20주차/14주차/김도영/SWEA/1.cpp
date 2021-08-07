#include<iostream>
#include <cstring>
 
using namespace std;
 
int score[101];
 
int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
     
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(score, 0, sizeof(score));
        int a; cin >> a;
         
        for(int i=0; i<1000; i++){
            int n; cin >> n;
            score[n] += 1;
        }
 
        int Max = 0, ans = 0;
        for(int i=1; i<=100; i++){
            if(Max <= score[i] ){
                Max = score[i];
                ans = i;
            }
        }
         
        cout << "#" << a << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}