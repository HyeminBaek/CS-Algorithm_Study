#include<iostream>
#include<queue>
using namespace std;
int N, K, s;
queue<int> q;
int main() {
	scanf("%d%d", &N, &K);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &s);
		if (!q.empty() && q.front() + K <= i) {
			q.pop();
		}
		if (s + q.size() % 2 == 1) {//전구가 켜있는 상태일 경우
			if (i + K - 1 >= N) {
				ans = -1;
				break;
			}
			ans++;
			q.push(i);
		}
	}
	if (ans == -1) {
		printf("Insomnia");
	}
	else {
		printf("%d\n", ans);
	}

	return 0;
}