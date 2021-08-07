#include<iostream>
#include<cstring>

using namespace std;

int N;
char arr[6562][6562];

void init() {
	cin >> N;
	memset(arr, ' ', sizeof(arr));
}

void solve(int n,int x,int y) {
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				solve(n / 3, x + (n / 3 * i), y + (n / 3 * j));
			}
		}
	}
}
int main(void) {
	init();
	solve(N, 0,0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}
