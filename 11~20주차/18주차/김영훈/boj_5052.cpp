#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int t, n;
string s[10000];
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		sort(s, s + n);
		bool answer = true;
		for (int i = 0; i < n - 1; i++) {
			int idx = 0;
			bool f = true;
			while (1) {
				if (idx == s[i].size() || idx == s[i].size()) {
					break;
				}
				if (s[i][idx] != s[i + 1][idx]) {
					f = false;
					break;
				}
				idx++;
			}
			if (f) {
				answer = false;
				break;
			}
		}
		cout << (answer ? "YES\n" : "NO\n");
	}
	return 0;
}
