#include<iostream>
using namespace std;
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	int answer = 0;
	while (M!=N) {
		if (N > M) {
			N -= M;
		}
		else {
			M -= N;
			answer += N;
		}

	}
	printf("%d\n", answer);
	return 0;
}