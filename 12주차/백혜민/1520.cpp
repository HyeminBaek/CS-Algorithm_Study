#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int dx[] = { 0,0,1,-1 };//왼쪽,오른쪽,아래
int dy[] = { -1,1,0,0 };
int map[500][500]; 
int dp[500][500];

int dfs(int x, int y)
{
	int& temp = dp[x][y];
	if (temp != -1) return temp; //이미 방문한 경우
	if (x == N - 1 && y == M - 1) return 1;

	temp = 0;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k]; int ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (map[nx][ny] < map[x][y])
				temp += dfs(nx, ny);
		}
	}
	return temp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(0,0);

	return 0;
}
