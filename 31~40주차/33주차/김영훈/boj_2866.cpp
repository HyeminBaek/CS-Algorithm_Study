#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int R, C;
string s[1000],input[1000];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < C; i++) {
		s[i] = "";

	}
	for (int i = 0; i < R; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < C; i++) {
		for (int j = R - 1; j >= 0; j--) {
			s[i] += input[j][i];
		}
	}
	sort(s, s + C);
	int length = 0;
	for (int i = 0; i < C - 1; i++) {
		int idx = 0;
		while (1) {
			if (idx == s[i].size() || idx == s[i + 1].size()) {
				break;
			}
			if (s[i][idx] != s[i + 1][idx]) {
				break;
			}
			idx++;
		}
		length = max(idx, length);

	}
	cout << R - length-1 << "\n";
	return 0;
}