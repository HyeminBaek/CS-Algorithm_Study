/*

	0 : ""      0: 7,  1: 1
	1 : 1       0: 2,  1: imp
	2 : 10      0: 3,  1: imp
	3 : 100     0: 3,  1: 4
	4 : 100+1   0: 7,  1: 5
	5 : 100+1+1  0: 6,    1: 5
	6 : 100+1+10  0: 3,  1: 0
	7 : 0        0: inf,  1: 0
	8 : imp

	*/


#include<iostream>
#include<string>
using namespace std;
int T;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	
	
	for (int tc = 0; tc < T; tc++) {
		cin >> s;
		int state = 0;
		for (int i = 0; i < s.size(); i++) {
			switch (state) {
				case 0:
					if (s[i] == '0') {
						state = 7;
					}
					else {
						state = 1;
					}
					break;
				case 1:
					if (s[i] == '0') {
						state = 2;
					}
					else {
						state = 8;
					}
					break;
				case 2:
					if (s[i] == '0') {
						state = 3;
					}
					else {
						state = 8;
					}
					break;
				case 3:
					if (s[i] == '0') {
						state = 3;
					}
					else {
						state = 4;
					}
					break;
				case 4:
					if (s[i] == '0') {
						state = 7;
					}
					else {
						state = 5;
					}
					break;
				case 5:
					if (s[i] == '0') {
						state = 6;
					}
					else {
						state = 5;
					}
					break;
				case 6:
					if (s[i] == '0') {
						state = 3;
					}
					else {
						state = 0;
					}
					break;
				case 7:
					if (s[i] == '0') {
						state = 8;
					}
					else {
						state = 0;
					}
					break;
			}
			
			if (state == 8) {
				break;
			}
		}
		
		if (state == 0 || state == 4 || state == 5) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}