#include<iostream>
#include<string>
using namespace std;
int d[1001][1001];
int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				if (d[i - 1][j] > d[i][j - 1]) {
					d[i][j] = d[i - 1][j];
				}
				else {
					d[i][j] = d[i][j - 1];
				}
			}
		}
	}
	cout << d[s1.length()][s2.length()] << '\n';
	return 0;
}
