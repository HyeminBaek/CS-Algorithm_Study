#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<string, long long> answer;
int N, M;
string kingdom[201][3];
vector<string> chk;

void init() {
	cin >> N >> M;
	cin >> kingdom[0][0];
	for (int i = 1; i <= N; i++) {
		cin >> kingdom[i][0] >> kingdom[i][1] >> kingdom[i][2];
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		chk.push_back(s);
	}
}

void bfs() {
	typedef long long LL;
	long long aa = 1LL << 52;
	answer[kingdom[0][0]] = aa;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer[kingdom[j][0]] = (answer[kingdom[j][1]] + answer[kingdom[j][2]]) / 2;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	bfs();
	long long maximum = 0;
	string result;
	for (int i = 0; i < M; i++) {
		if (answer[chk[i]] > maximum) {
			maximum = answer[chk[i]];
			result = chk[i];
		}
	}
	cout << result;
	return 0;
}
