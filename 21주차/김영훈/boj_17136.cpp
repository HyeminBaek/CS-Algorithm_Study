#include<iostream>
using namespace std;
int map[10][10],n[5],answer;
bool isPaste(int r, int c, int sz) {
	if (r + (sz - 1)>= 10 || c + (sz - 1) >= 10) {
		return false;
	}
	for (int i = r; i < r+sz; i++) {
		for (int j = c; j < c + sz; j++) {
			if (map[i][j] == 0 || map[i][j]==2) {
				return false;
			}
		}
	}
	return true;
}
void Fill(int r, int c, int sz, int n) {
	for (int i = r; i < r + sz; i++) {
		for (int j = c; j < c + sz; j++) {
			map[i][j] = n;
		}
	}
}
void DFS(int r, int c, int k) {
	if (r == 10 && c == 0) {
		answer = answer > k ? k : answer;
		return;
	}
	if (map[r][c] == 0 || map[r][c]==2) {
		DFS(r+(c+1)/10, (c+1)%10, k);
	}
	else {
		for (int i = 0; i < 5; i++) {
			
			if (n[i]>0 && isPaste(r, c, i + 1)) {
				Fill(r, c, i + 1, 2);
				n[i]--;
				DFS(r + (c + 1) / 10, (c + 1) % 10, k+1);
				n[i]++;
				Fill(r, c, i + 1, 1);
			}
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		n[i] = 5;
	}
	answer = 5 * 5 + 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			
		}
	}
	DFS(0, 0,0);
	if (answer == 5 * 5 + 1) {
		answer = -1;
	}
	printf("%d\n", answer);
	return 0;
}
