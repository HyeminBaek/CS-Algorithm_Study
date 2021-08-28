#include<iostream>
#include<string>
using namespace std;
string s;
long long k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> k;
	k--;
	int idx = s.size() - 1;
	bool f = true;
	while (1) {
		if (idx == -1) {
			f = (k == 0);
			break;
		}
		if (s[idx]=='1' || s[idx]=='2' || s[idx]=='6' || s[idx]=='7') {
			if (k % 2 == 1) {
				s[idx] = s[idx]>'2'?s[idx]:s[idx]+5;
			}
			else {
				s[idx] = s[idx] > '2' ? s[idx]-5 : s[idx];
			}
			k >>= 1;
		}
		idx--;
	}
	if (f) {
		cout << s << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}