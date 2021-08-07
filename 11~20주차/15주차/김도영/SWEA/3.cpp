#include<iostream>
#include <cstring>

using namespace std;

int n;
int score[101];
bool dp[100001];

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
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        cin >> n;
        int Max = 0, ans = 0;
        for(int i=0; i<n; i++){
            cin >> score[i];
            Max += score[i];

            //0부터 시작하면 중복이 발생할 수 있기 때문에
            for(int j=Max; j>=0; j--){
                if(dp[j])
                    dp[j+score[i]] = true;
            }
        }
        
        for(int i=0; i<=Max; i++){
            if(dp[i]) ans++;
        }
       
        
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}