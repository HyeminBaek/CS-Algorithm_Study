#include<iostream>
#include<string>
#include<vector>
using namespace std;
int T, N, checkalp[2][26];
string s[100],s2,s3;
vector<string> v;
int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		v.clear();
		for (int i = 0; i < N; i++) {
			cin >> s[i];
			
		}
		cin >> s2 >> s3;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 26; j++) {
				checkalp[0][j] = -1;
				checkalp[1][j] =-1;
			}
			bool ismatch = true;
			if (s[i].size() != s2.size()) continue;
			for (int j = 0; j < s[i].size(); j++) {
				int asc1 = s[i][j] - 'a';
				int asc2 = s2[j] - 'a';
				if (checkalp[0][asc1] == -1 && checkalp[1][asc2] == -1) {
					checkalp[0][asc1] = asc2;
					checkalp[1][asc2] = asc1;
				}
				else if (checkalp[0][asc1] != -1 && checkalp[1][asc2] != -1) {
					if (checkalp[0][asc1] != asc2 || checkalp[1][asc2] != asc1) {
						ismatch = false;
						break;
					}

				}
				else {
					ismatch = false;
					break;
				}
			}
			if (ismatch) {			
				v.push_back(s[i]);			
			}
		}
		if (v.size()==0) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			int ct = 0;
			for (int i = 0; i < 26; i++) {
				checkalp[0][i] = -1;
			}
			for (int i = 0; i < s2.size(); i++) {
				char c = v[0][i];
				bool f = true;
				for (int j = 1; j < v.size(); j++) {
					if (v[j][i] != c) {
						f = false;
						break;
					}
				}
				if (f) {
					checkalp[0][c - 'a'] = s2[i]-'a';
				}
			}
			int a=0, b=0;
			for (int i = 0; i < 26; i++) {
				if (checkalp[0][i] != -1) {
					ct++;
					a |= (1 << i);
					b |= (1 << checkalp[0][i]);
				}

			}
			if (ct == 25) {
				int c, d;
				for (int i = 0; i < 26; i++) {
					
					if ((a & (1 << i)) == 0) {
						c = i;
					}
					if ((b & (1 << i)) == 0) {
						d = i;
					}
				}
				checkalp[0][c] = d;
			}
			string answer = "";
			for (int i = 0; i < s3.size(); i++) {
				int t = checkalp[0][s3[i] - 'a'];
				if (t == -1) {
					answer += '?';
				}
				else {
					answer += (t + 'a');
				}
			}
			cout << answer << "\n";
		}
	}
	return 0;
}
