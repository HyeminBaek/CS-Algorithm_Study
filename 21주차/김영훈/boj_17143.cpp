#include<iostream>
using namespace std;
struct Shark {
	int s = 0;
	int d = 0;
	int z = 0;
};
int R, C, M, r, c, s, d, z;
Shark map[100][100];
int main() {
	scanf("%d%d%d", &R, &C, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
		map[r - 1][c - 1].s = s;
		map[r - 1][c - 1].d = d;
		map[r - 1][c - 1].z = z;
		if (d <= 2) {
			map[r - 1][c - 1].s %= (2 * R - 2);
		}
		else {
			map[r - 1][c - 1].s %= (2 * C - 2);
		}
	}

	int answer = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (map[j][i].z > 0) {
				answer += map[j][i].z;
				map[j][i].z = 0;
				break;
			}
		}

		Shark nmap[100][100];
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				nmap[j][k].z = 0;
			}
		}

		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {

				if (map[j][k].z > 0) {
					s = map[j][k].s;
					d = map[j][k].d;
					r = j;
					c = k;
					while (s > 0) {
						switch (d) {
						case 1:
							if (s >= r) {
								s -= r;
								r = 0;
								d++;
							}
							else {
								r = r - s;
								s = 0;

							}


							break;
						case 2:
							if (s >= R - 1 - r) {
								s -= (R - 1 - r);
								r = R - 1;
								d--;
							}
							else {
								r = r + s;
								s = 0;
							}

							break;
						case 3:
							if (s >= C - 1 - c) {
								s -= (C - 1 - c);
								c = C - 1;
								d++;
							}
							else {
								c = c + s;
								s = 0;
							}

							break;
						case 4:

							if (s >= c) {
								s -= c;
								c = 0;
								d--;
							}
							else {
								c = c - s;
								s = 0;
							}


							break;
						}
					}

					if (nmap[r][c].z < map[j][k].z) {
						nmap[r][c] = map[j][k];
						nmap[r][c].d = d;
					}

				}
			}
		}

		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				map[j][k] = nmap[j][k];
			}

		}

	}
	printf("%d\n", answer);
	return 0;
}