#include<iostream>
using namespace std;
int N, M, H,a,b,answer;
bool l[11][31];
void Search(int h, int n, int pos[10]) {
	if (h == H+1) {
		
		for (int i = 1; i <= N; i++) {
			
			if (pos[i] != i) {
				return;
			}
		}
	
		answer = answer > n ? n : answer;
		return;
	}
	int npos[10],comb[3];
	for (int i = 0; i <= 3; i++) {
		if (n + i > 3 || i>=N) {
			break;
		}
		for (int j = 0; j < i; j++) {
			comb[j] = j + 1;
		}
		while (1) {
			bool f = true;
			
			for (int j = 0; j<i; j++) {
				if (l[comb[j] - 1][h] || l[comb[j]][h] || l[comb[j] + 1][h]) {
					f = false;
					break;
				}
				if (j < i - 1 && comb[j + 1] == comb[j] + 1) {
					f = false;
					break;
				}
			}
			if (f) {
				
				for (int j = 0; j < i; j++) {
					l[comb[j]][h] = true;
				}
				
				for (int i = 1; i <= N; i++) {
					if (i<N && l[i][h]) {
						npos[i] = pos[i + 1];
						npos[i + 1] = pos[i];
						i++;
					}
					else {
						npos[i] = pos[i];
					}
				}
				
				Search(h + 1, n+i, npos);

				for (int j = 0; j < i; j++) {
					l[comb[j]][h] = false;
				}
			}
			int idx = i-1;
			while (idx >= 0 && comb[idx] == N + idx - i) {
				idx--;
			}
			if (idx == -1) {
				break;
			}
			comb[idx]++;
			for (int j = idx + 1; j < i; j++) {
				comb[j] = comb[j - 1] + 1;
			}
			
		}
		


	}
	
}
int main() {
	scanf("%d%d%d", &N, &M, &H);
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			l[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		l[b][a] = true;
	}
	int p[10];
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	answer = 4;
	Search(1, 0, p);
	if (answer == 4) {
		answer = -1;
	}
	printf("%d\n", answer);
	return 0;
}