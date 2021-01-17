#include<iostream>

using namespace std;

int D, K, d1, d2;
int d[31][3];
void init() {
	cin >> D >> K;
	d[1][1] = 1;
	d[1][2] = 0;
	d[2][1] = 0;
	d[2][2] = 1;
	for (int i = 3; i <= D; i++) { // 계수 계산하기
		d[i][1] = d[i - 1][1] + d[i - 2][1];
		d[i][2] = d[i - 1][2] + d[i - 2][2];
	}
}

void solution() {
	int a = 1, b;
	while (1) {
		if ((K - d[D][1] * a) % d[D][2] == 0) {
			b = (K - d[D][1] * a) / d[D][2];
			break;
		}
		a++;
	}
	d1 = a; d2 = b;
}

int main(void) {
	init();
	solution();
	cout << d1 << '\n' << d2;
	return 0;
}
