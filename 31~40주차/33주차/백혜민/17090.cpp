#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
미로에서 탈출 가능한 칸의 수->경계 벗어나기

*/

int N, M, answer;
int arr[501][501];
bool visited[501][501];
vector<pair<int, int>> v;

int dir[][2] = { {0,1},{-1,0},{0,-1},{1,0} }; //URDL

void bfs(int i, int j)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ i,j }); visited[i][j] = true; answer += 1;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dir[k][0], ny = y + dir[k][1];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (!visited[nx][ny]&&arr[nx][ny]==(k+2)%4)
				{
					visited[nx][ny] = true;
					q.push({ nx,ny }); answer += 1;
				}
			}
		}
	}
}
void sol()
{
	for (int i = 0; i < v.size(); i++)
		bfs(v[i].first, v[i].second);

	cout << answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			char c; cin >> c;
			switch (c)
			{
			case 'R': arr[i][j] = 0;	break;
			case 'U': arr[i][j] = 1;	break;
			case 'L': arr[i][j] = 2;	break;
			case 'D': arr[i][j] = 3;	break;
			}
			int nx = i + dir[arr[i][j]][0], ny = j + dir[arr[i][j]][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) v.push_back({ i,j });
		}
	}
}
int main()
{
	init();
	sol();
	return 0;
}