#include<iostream>
#include<cstring>
using namespace std;

int N;
long B;
long arr[5][5], result[5][5], calc[5][5];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	result[0][0] = 1, result[1][1] = 1, result[2][2] = 1, result[3][3] = 1, result[4][4] = 1; // E 
}

void multiple(long a[5][5], long b[5][5]) {
	memset(calc, 0, sizeof(calc));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				calc[i][j] += (a[i][k] * b[k][j]) % 1000;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = calc[i][j];
		}
	}
}

void solve() {
	init();
	while (B > 0) {
		if (B % 2 == 1) {
			multiple(result, arr);
		}
		multiple(arr, arr);
		B /= 2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<< result[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	solve();
	return 0;
}
