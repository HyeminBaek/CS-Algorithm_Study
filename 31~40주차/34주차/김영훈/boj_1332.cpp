#include<iostream>
#include<algorithm>
using namespace std;
int N, V,P,pos[1001][2];
int main() {
	scanf("%d%d", &N, &V);
	for (int i = 0; i <=1000; i++) {
		pos[i][0] = -1;
		pos[i][1] = -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &P);
		if (pos[P][i%2] == -1) {
			pos[P][i%2] = i;
		}
	}
	int ans = N;
	for (int i = 0; i <= 1000; i++) {
		if (pos[i][0] != -1) {
			for (int j = i + V; j <= 1000; j++) {
				if (pos[j][0] != -1) {
					int minidx = min(pos[i][0], pos[j][0]);
					int maxidx = max(pos[i][0], pos[j][0]);
				
					ans = min(ans, (minidx+1) / 2 + 1 + (maxidx - minidx + 1) / 2);
				}
				if (pos[j][1] != -1) {
					int minidx = min(pos[i][0], pos[j][1]);
					int maxidx = max(pos[i][0], pos[j][1]);
				
					ans = min(ans, (minidx+1) / 2 + 1 + (maxidx - minidx + 1) / 2);
				}
			}
		}
		if (pos[i][1] != -1) {
			for (int j = i + V; j <= 1000; j++) {
				if (pos[j][0] != -1) {
					int minidx = min(pos[i][1], pos[j][0]);
					int maxidx = max(pos[i][1], pos[j][0]);
				

					ans = min(ans, (minidx+1) / 2 + 1 + (maxidx - minidx + 1) / 2);
				}
				if (pos[j][1] != -1) {
					int minidx = min(pos[i][1], pos[j][1]);
					int maxidx = max(pos[i][1], pos[j][1]);
					

					ans = min(ans, (minidx+1) / 2 + 1 + (maxidx - minidx + 1) / 2);
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}