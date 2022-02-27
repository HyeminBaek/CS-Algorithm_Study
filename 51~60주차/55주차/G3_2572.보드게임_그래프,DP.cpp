#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, char> pic;
int N, M, K,a,b,dp[2][501];
char cards[1010],c;
vector<pic> adjList[505];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
       cin >> cards[i];
    }
    cin >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
   
        adjList[a - 1].push_back(pic(b - 1, c));
        adjList[b - 1].push_back(pic(a - 1, c));   
    }

  
    for (int i = 0; i < M; i++) {
        dp[0][i] = -1;
        dp[1][i] = -1;
    }
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int now = i % 2;
        int next = 1 - now;
        for (int j = 0; j < M; j++) {
            dp[next][j] = -1;
        }
        for (int j = 0; j < M; j++) {
            if (dp[now][j] == -1) continue;
            for (int k = 0; k < adjList[j].size(); k++) {
                pic* edge = &adjList[j][k];
                dp[next][edge->first] = max(dp[next][edge->first], dp[now][j] + (cards[i] == edge->second) * 10);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans = max(ans, dp[N % 2][i]);
    }
    cout << ans << "\n";
    return 0;
}