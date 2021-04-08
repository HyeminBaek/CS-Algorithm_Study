/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <cstring>
#include <queue>

const int MAX = 100;
using namespace std;

int n;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void Search(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            if(dp[y][x] + map[ny][nx] < dp[ny][nx]){
                dp[ny][nx] = dp[y][x] + map[ny][nx];
                q.push({ny, nx});
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    
	int test_case;
	int T;
	
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));
        cin >> n;      
        for(int i=0; i<n; i++){
            string s; cin >> s;
            for(int j = 0; j<n; j++){
				map[i][j] = s[j]-'0';
                dp[i][j] = 987654321;
            }
        }
        
        Search();
        cout << "#" << test_case << " " << dp[n-1][n-1] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}