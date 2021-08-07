#include<iostream>
#include<algorithm>
using namespace std;
int T, N, K, p1, p2, dist[100000];
int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &K);
		scanf("%d", &p1);
		for (int i = 0; i < N - 1; i++) {
			scanf("%d", &p2);
			dist[i] = p2 - p1;
			p1 = p2;
		}
		int ans = 0;
		sort(dist, dist + N - 1);
		for (int i = N - 2 - (K - 1); i >= 0; i--) {
			ans += dist[i];
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}