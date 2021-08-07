#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, H, W, sr, sc, fr, fc;
bool map[1000][1000];
vector<pair<int, int>> wall;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool check(int nx,int nex,int ny,int ney)
{
	for (int i = 0; i < wall.size(); i++)
	{
		if (wall[i].first >= nx && wall[i].first <= nex)
		{
			if (wall[i].second >= ny && wall[i].second <= ney) return false;
		}
	}
	return true;
}
int bfs()
{
	queue<pair<int, int>> q;
	q.push({ sr,sc });

	int visited[1000][1000];
	memset(visited, -1 , sizeof(visited));
	visited[sr][sc] = 0;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		int endx = x + H, endy = y + W;
		q.pop();

		//cout << x << " " << y << endl;
		if (x == fr && y == fc)
		{
			return visited[x][y];
		}
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			int nex = endx + dx[k], ney = endy + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (0 <= nex && nex < N && 0 <= ney && ney < M)
				{
					if (check(nx, nex, ny, ney) && visited[nx][ny] == -1)
					{
						visited[nx][ny] = visited[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j])
				wall.push_back({ i,j });
		}
	}
	
	cin >> H >> W >> sr >> sc >> fr >> fc;
	H--, W--, sr--, sc--, fr--, fc--;

	cout << bfs();

	return 0;
}
