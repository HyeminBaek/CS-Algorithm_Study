#include<iostream>
#include<string>
using namespace std;
string input;
int sz,dp[100001][3],open[100001];
int main() {
	ios::sync_with_stdio(false);
	cin >> input;
	open[0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= input.size(); i++) {
		
		if (input[i - 1] == '(') {
			open[i] = open[i - 1] + 1;
		}
		else {
			open[i] = open[i - 1] - 1;
		}
		dp[i][0] = dp[i - 1][0] * (open[i] >= 0);//º¯°æX
		dp[i][1] =dp[i - 1][1]*(open[i]>=2);//open ->close
		dp[i][2] = dp[i - 1][2]; //close->open
		if (input[i - 1] == '(') {
			dp[i][1] += dp[i-1][0] * (open[i] >= 2);
		}
		else {
			dp[i][2] += dp[i-1][0];
		}
		
	}
	if (open[input.size()] == 2) {
		cout << dp[input.size()][1] << "\n";
	}
	else if(open[input.size()]==-2){
		cout << dp[input.size()][2] << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	return 0;
}