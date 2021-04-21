#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N, M, map[2][8][8],num,answer;
pii dir[4] = {pii(-1,0), pii(0,1),pii(1,0),pii(0,-1) };
void Check(int r, int c, int d,int k) {
	while (r < N && r >= 0 && c < M && c >= 0) {
		if (map[0][r][c] == 6) {
			return;
		}
		if (map[0][r][c] == 0) {
			if (k == 1) {
				map[1][r][c]++;
				if (map[1][r][c] == 1) {
					num--;
				}
			}
			else {
				map[1][r][c]--;
				if (map[1][r][c] == 0) {
					num++;
				}
			}
		}
		r += dir[d].first;
		c += dir[d].second;
	}
}
void Search(int pos) {
	if (pos == N * M) {	
		
		answer = answer > num ? num : answer;
		return;
	}
	int r = pos / M,c=pos%M;
	switch (map[0][r][c]) {
	case 1:
		for (int i = 0; i < 4; i++) {
			Check(r, c, i, 1);		
			Search(pos + 1);
			Check(r, c, i, -1);		
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			Check(r, c, i, 1);
			Check(r, c, (i + 2) % 4, 1);
			Search(pos + 1);
			Check(r, c, i, -1);
			Check(r, c, (i + 2) % 4, -1);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			Check(r, c, i, 1);
			Check(r, c, (i + 1) % 4, 1);
			Search(pos + 1);
			Check(r, c, i, -1);
			Check(r, c, (i + 1) % 4, -1);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			Check(r, c, i, 1);
			Check(r, c, (i + 1) % 4, 1);
			Check(r, c, (i + 2) % 4, 1);
			Search(pos + 1);
			Check(r, c, i, -1);
			Check(r, c, (i + 1) % 4, -1);
			Check(r, c, (i + 2) % 4, -1);
		}
		break;
	case 5:
		for (int i = 0; i < 4; i++) {
			Check(r, c, i, 1);
		}
		Search(pos + 1);
		for (int i = 0; i < 4; i++) {
			Check(r, c, i, -1);
		}
		break;
	default :
		Search(pos + 1);
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[0][i][j]);
			num += (map[0][i][j] == 0);
			map[1][i][j] = 0;
		}
	}
	answer = N * M;
	Search(0);
	printf("%d\n", answer);
	return 0;
}