#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s, answer;
int reverse_chk[10002];
void init() {
	cin >> s;
}
/* 재귀로 하면 시간초과가 남..
void dfs(int n, string word) {
	if (n == s.size() + 1) {
		if (word < answer) {
			answer = word;
		}
		return;
	}
	dfs(n + 1, word);
	reverse(&word[0], &word[n]);
	dfs(n + 1, word);
}
*/
/*  같은 크기의 문자열이 나올 떄 뒤집을지 안뒤집을지 판단하기 어려웠음
void greedy() {
	int size = s.size() - 1;
	bool chk = true;
	for (int i = size; i >= 0; i--) {
		if (chk) {
			if (s[i] > s[0]) {
				continue;
			}
			else {
				chk = false;
				reverse_chk[i] = 1;
			}
		}
		else {
			if (s[i] >= s[0]) {
				chk = true;
				reverse_chk[i] = 1;
			}
			else {
				continue;
			}
		}
	}
}
*/
void solution() {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] > s[i - 1]) {
			char cpy = s[i];
			s.erase(i, 1);
			s = cpy + s;
		}
	}
}
int main(void) {
	init();
	//greedy();
	//dfs(1,s);
	solution();
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}
