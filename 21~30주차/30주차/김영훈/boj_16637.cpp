#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = ((ll)1 << 62);
ll dp[10][2];
int N;
string s;
ll oper(ll a, ll b, char op) {
	ll ret = a;
	switch (op) {
	case '+':
		ret += b;
		break;
	case '-':
		ret -= b;
		break;
	case '*':
		ret *= b;
		break;
	}
	return ret;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> s;
	for (int i = 0; i <= N / 2; i++) {
		dp[i][0] = -INF;
		dp[i][1] = INF;
	}
	dp[0][0] = (ll)s[0] - '0';
	dp[0][1] = (ll)s[0] - '0';
	for (int i = 2; i < N; i += 2) {
		ll k = (ll)s[i] - '0';
		switch (s[i - 1]) {
		case '+':
		case '-':

			dp[i / 2][0] = max(dp[i / 2][0], oper(dp[i / 2-1][0], k, s[i - 1]));
			dp[i / 2][1] = min(dp[i / 2][1], oper(dp[i / 2-1][1], k, s[i - 1]));
			break;
		case '*':
			if (k > 0) {
				dp[i / 2][0] = max(dp[i / 2][0], oper(dp[i / 2-1][0], k, s[i - 1]));
				dp[i / 2][1] = min(dp[i / 2][1], oper(dp[i / 2-1][1], k, s[i - 1]));
			}
			else {
				dp[i / 2][0] = max(dp[i / 2][0], oper(dp[i / 2-1][1], k, s[i - 1]));
				dp[i / 2][1] = min(dp[i / 2][1], oper(dp[i / 2-1][0], k, s[i - 1]));
			}
			break;
		}
		if (i < N - 1) {
			k = oper((ll)s[i] - '0', (ll)s[i + 2] - '0', s[i + 1]);
			switch (s[i - 1]) {
			case '+':
			case '-':
				dp[i / 2 + 1][0] = max(dp[i / 2 + 1][0], oper(dp[i / 2-1][0], k, s[i - 1]));
				dp[i / 2 + 1][1] = min(dp[i / 2 + 1][1], oper(dp[i / 2-1][1], k, s[i - 1]));
				break;
			case '*':
				if (k > 0) {
					dp[i / 2 + 1][0] = max(dp[i / 2 + 1][0], oper(dp[i / 2-1][0], k, s[i - 1]));
					dp[i / 2 + 1][1] = min(dp[i / 2 + 1][1], oper(dp[i / 2-1][1], k, s[i - 1]));
				}
				else {
					dp[i / 2 + 1][0] = max(dp[i / 2 + 1][0], oper(dp[i / 2-1][1], k, s[i - 1]));
					dp[i / 2 + 1][1] = min(dp[i / 2 + 1][1], oper(dp[i / 2-1][0], k, s[i - 1]));
				}
				break;
			}
		}

		
	}
	cout << dp[N / 2][0] << "\n";
	return 0;
}