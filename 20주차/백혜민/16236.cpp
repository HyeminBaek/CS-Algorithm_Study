#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;

struct shark
{
	int sx, sy, size, eaten;
};
int N;
shark baby;
int map[20][20];
int visited[20][20];
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1,0,0 };

int dist()
{
	queue<pair<int, int>> q; q.push({ baby.sx,baby.sy });
	priority_queue<pair<int,pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;

	memset(visited, -1, sizeof(visited));
	visited[baby.sx][baby.sy] = 0;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] <= baby.size&&visited[nx][ny] == -1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
					if (map[nx][ny] > 0 &&map[nx][ny]<baby.size) pq.push({ visited[nx][ny],{nx,ny} });
				}
			}
		}
	}
	if (!pq.empty())
	{
		baby.sx = pq.top().second.first, baby.sy = pq.top().second.second;
		baby.eaten += 1; map[baby.sx][baby.sy] = 0;
		
		if (baby.eaten == baby.size) baby.size += 1, baby.eaten = 0;

		return pq.top().first;
	}
	else return -1;
}
int movingShark()
{
	int time = 0;

	while (1)
	{
		int result = dist();
		if (result == -1) break;

		time += result;
	}

	return time;
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
			cin >> map[i][j];

			if (map[i][j] == 9)
			{
				baby = { i,j,2,0 }; map[i][j] = 0;
			}
		}
	}
}
int main()
{
	init();
	cout << movingShark();

	return 0;
}
