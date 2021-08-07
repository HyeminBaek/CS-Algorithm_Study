#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int N, K, result;
vector<string> word;
bool ack[26];

/*
1. K < 5 이면 읽을 수 있는 글자가 없다.
2. 다 탐색해서 읽을 수 있는 단어의 최대 갯수를 찾자.
*/
void init() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		word.emplace_back(s.substr(4,s.size() - 8));
	}
}
void dfs(int x, int cnt) {
	if (cnt == K) {
		int num = 0;
		for (int i = 0; i < N; i++) {
			int chk = 1;
			for (int j = 0; j < word[i].size(); j++) {
				if (!ack[word[i][j] - 97]) {
					chk = 0;
					break;
				}
			}
			if (chk) {
				num++;
			}
		}
		result = max(result, num);
		return;
	}
	for (int i = x; i < 26; i++) {
		if (ack[i]) {
			continue;
		}
		ack[i] = true;
		dfs(i, cnt + 1);
		ack[i] = false;
	}
}
int main(void) {
	init();

	if (K < 5) {
		cout << 0;
		return 0;
	}

	ack[0] = true; // a
	ack[2] = true; // c
	ack[8] = true; // i
	ack[13] = true; // n
	ack[19] = true; // t
	K -= 5;
	dfs(0,0);
	cout << result;
	return 0;
}
