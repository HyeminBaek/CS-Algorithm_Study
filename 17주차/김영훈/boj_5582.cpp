#include<iostream>
#include<string>
using namespace std;
string s[2];
int dp[2][4000], visit[2][4000],answer;
int main() {
	ios::sync_with_stdio(false);
	cin >> s[0] >> s[1];

	for (int i = 0; i < s[1].size(); i++) {
		visit[0][i] = -1;
		visit[1][i] = -1;
	}
	answer = 0;
	for (int i = 0; i < s[0].size(); i++) {
		if (s[0][i] == s[1][0]) {
			dp[i % 2][0] = 1;
			visit[i % 2][0] = i;
		}
		for (int j = 1; j < s[1].size(); j++) {
			if (s[0][i] == s[1][j]) {
				if (visit[1 - (i % 2)][j - 1] == i - 1) {
					dp[i % 2][j] = dp[1 - (i % 2)][j - 1] + 1;		
				}
				else {
					dp[i % 2][j] = 1;		
				}
				answer = answer < dp[i % 2][j] ? dp[i % 2][j] : answer;
				visit[i % 2][j] = i;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}