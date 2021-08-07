#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

struct Info {
	pii pos;
	int age;
	Info(pii pos, int age) {
		this->pos = pos;
		this->age = age;
	}
};
int N, M, K, A[10][10],nmap[10][10],wmap[10][10][2000],wmax[10][10],x,y,z;
pii d[8] = { pii(-1,-1),pii(-1,0),pii(-1,1),pii(0,-1),pii(0,1),pii(1,-1),pii(1,0),pii(1,1) };
void SpringToSummer() {
	int temp[2000];
	int nmax,add;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[1] = 0;
			nmax = 0;
			add = 0;
			for (int k = 1; k <= wmax[i][j]; k++) {
				
				if (nmap[i][j] / k >= wmap[i][j][k]) {
					temp[k + 1] = wmap[i][j][k];

				}
				else {
					temp[k + 1] = nmap[i][j] / k;
				}
				
				if (temp[k + 1] > 0) {
					nmax = k + 1;
				}
				nmap[i][j] -= temp[k + 1] * k;
				add += (wmap[i][j][k] - temp[k + 1])* (k/ 2);

			}
			nmap[i][j] += add;
			wmax[i][j] = nmax;
			for (int l = 1; l <=nmax; l++) {
				wmap[i][j][l] = temp[l];
			}
		}
	}
	
}

void Fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 5; k <= wmax[i][j]; k += 5) {
				for (int l = 0; l < 8; l++) {
					int nr = i + d[l].first;
					int nc = j + d[l].second;
					if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
						wmax[nr][nc] = wmax[nr][nc] < 1 ? 1 : wmax[nr][nc];
						wmap[nr][nc][1]+=wmap[i][j][k];
					}
				}
			}
		}
	}
	
}
void Winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nmap[i][j] += A[i][j];
		}
	}
}
void OneYear() {
	SpringToSummer();
	
	Fall();
	Winter();
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nmap[i][j] = 5;
			scanf("%d", &A[i][j]);
			wmax[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2000; k++) {
				wmap[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &x, &y, &z);
		wmap[x - 1][y - 1][z]++;
		wmax[x - 1][y - 1] = wmax[x - 1][y - 1] < z ? z : wmax[x - 1][y - 1];
	}
	while (K--) {
		OneYear();
		
		
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 1; k <= wmax[i][j]; k++) {
				answer += wmap[i][j][k];
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}

