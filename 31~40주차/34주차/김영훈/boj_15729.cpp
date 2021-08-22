#include<iostream>
using namespace std;
int N, arr[1000000],s[1000000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		s[i] = 0;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] % 2 != arr[i] % 2) {
			ans++;
			if (i < N - 1) {
				arr[i + 1]++;
			}
			if (i < N - 2) {
				arr[i + 2]++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}