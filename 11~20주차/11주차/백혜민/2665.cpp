#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[50][50];
int visited[50][50];

void bfs()
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { 1,-1,0,0 };

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] == 1&& visited[nx][ny] > visited[x][y])
				{
					visited[nx][ny] = visited[x][y];
					q.push({ nx,ny });
				}
				if (map[nx][ny] == 0&& visited[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c; cin >> c;
			map[i][j] = c - '0';
			visited[i][j] = 98765;
		}
	}
}
int main()
{
	init();
	bfs();
	cout << visited[N - 1][N - 1];

	return 0;
}
