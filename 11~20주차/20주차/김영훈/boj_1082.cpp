#include<iostream>
#include<string>
using namespace std;
string CompStr(string s1, string s2) {
	if (s1.size() > s2.size()) {
		return s1;
	}
	else if (s1.size() < s2.size()) {
		return s2;
	}
	else {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] > s2[i]) {
				return s1;
			}
			else if (s1[i] < s2[i]) {
				return s2;
			}
		}
	}
	return s1;
}
string dp[51];
int N, cost[10],money;
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}
	cin >> money;
	for (int i = 0; i <= money; i++) {
		dp[i] = "";
	}
	string answer = "";
	for (int i = 0; i <= money; i++) {
		answer = CompStr(answer, dp[i]);
		
		for (int j = 0; j < N; j++) {
			if (i + cost[j] > money) continue;
			if (j == 0 && dp[i].size() == 0) continue;
			string n = dp[i] + (char)(j + '0');
			dp[i + cost[j]] = CompStr(dp[i + cost[j]], n);
		}
	}
	if (answer == "") {
		answer = "0";
	}
	cout << answer << "\n";
	
	return 0;
}