#include<iostream>
using namespace std;
int N, M,result[100][10],score[100];
bool solved[10];
int main() {
	bool f = true;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		solved[i] = false;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
		if (score[i] == M || score[i]==0) {
			f = false;
		}
		int num = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &result[i][j]);
			
			if (result[i][j] == 1) {
				solved[j] = true;
				score[i]--;
			}
			if (result[i][j] == -1) {
				num++;
			}

		}
		if (score[i] > num) {
			f = false;
		}
	}
	if (f) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = M - 1; j >= 0; j--) {
				if (score[i] == 0) {
					break;
				}
				if (!solved[j] && result[i][j]==-1) {
					solved[j] = true;
					score[i]--;
				}
			}
		}
	
		for (int i = 0; i < M; i++) {
			if (!solved[i]) {
				f = false;
				break;
			}
		}
		
	}
	printf("%s\n", (f ? "YES" : "NO"));
	return 0;
}