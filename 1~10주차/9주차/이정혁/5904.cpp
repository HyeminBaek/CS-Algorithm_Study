#include<iostream>

using namespace std;
string moo = "moomooomoo";
long long arr[32];
long long N;
// 

void solve() {
	arr[3] = 3;
	int i = 4;
	while (1) {
		arr[i] = 2 * arr[i - 1] + i;
		if (arr[i] > N) {
			break;
		}
		i++;
	}

	while (1) {
		if (i == 4) {
			cout << moo[N - 1];
			break;
		}
		else {
			if (N - arr[i - 1] <= i) {
				if (N - arr[i - 1] >= 0) {// 2번째 파트
					if (N - arr[i - 1] == 1) {
						cout << "m";
						break;
					}
					else {
						cout << "o";
						break;
					}
				}
			}
			else { // 3번째 파트
				N = N - arr[i - 1] - i;
			}
		}
		i--;
	}
}
int main(void) {
	cin >> N;
	solve();
	return 0;
}
