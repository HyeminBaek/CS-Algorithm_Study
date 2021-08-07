#include<iostream>
using namespace std;
int N, arr[50], next_n;
int GCD(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	while (a != 0) {
		int r = b%a;
		b = a;
		a = r;
	}
	return b;
}
int ABS(int a) {
	return a < 0 ? -a : a;
}
bool isCorrect(int a) {

	int b = arr[1] - arr[0] * a;
	for (int i = 2; i < N; i++) {
		if (arr[i - 1] * a + b != arr[i]) return false;
	}

	next_n = arr[N - 1] * a + b;
	return true;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int num = 0;
	if (N==1) {
		num = 2;
	}else if(N==2){
		if (arr[0] == arr[1]) {
			num = 1;
			next_n = arr[1];
		}
		else {
			num = 2;
		}
	}
	else {
		int gcd = ABS(arr[2] - arr[1]);
		for (int i = 3; i < N; i++) {
			gcd = GCD(gcd, ABS(arr[i] - arr[i - 1]));
		}
		if (gcd == 0) {// arr[1]~arr[N-1] 값이 모두 같음
			num = 1;
			next_n = arr[N - 1];
		}
		else {
			//a=0일경우
			num += isCorrect(0);
			for (int i = 1; i * i <= gcd; i++) {
				if (gcd % i == 0) {
					//a값의 후보들 : i, N/i, -i, -N/i
					num += isCorrect(i);
					num += isCorrect(-i);

					if (i * i != gcd) {
						num += isCorrect(gcd / i);
						num += isCorrect(-(gcd / i));
					}

				}
			}
		}
		
	}
	switch (num) {
	case 0:
		printf("B\n");
		break;
	case 1:
		printf("%d\n", next_n);
		break;
	default:
		printf("A\n");
		break;

	}
	return 0;
}