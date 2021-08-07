#include<iostream>

using namespace std;

int N, M, K, a, b;
int arr[20][20];
int movement[2][2] = { {0,1},{1,0} };
bool visited[20][20];
int result[20][20];
void init() {
	cin >> N >> M >> K;
	int num = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1 || j == 1) {
				result[i][j] = 1;
			}
			if (num == K) {
				a = i;
				b = j;
			}
			arr[i][j] = num;
			num++;
		}
	}
}

void bfs(int sx, int sy, int dx, int dy) {
	for (int i = sx; i <= dx; i++) {
		for (int j = sy; j <= dy; j++) {
			result[i][j] = result[i - 1][j] + result[i][j - 1];
		}
	}
}
int main(void) {
	init();
	if (K == 0) {
		a = N; b = M;
		bfs(2, 2, N, M);
		cout << result[N][M];
		return 0;
	}
	bfs(2, 2, a, b);
	for (int i = a; i <= N; i++) {
		for (int j = b; j <= M; j++) {
			if (i == a || j == b) {
				result[i][j] = result[a][b];
			}
		}
	}
	bfs(a + 1, b + 1, N, M);
	cout << result[N][M];
	return 0;
}
