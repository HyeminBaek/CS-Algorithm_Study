#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int answer;
int map[501][501];

int dx[19][4] = { {0,0,0,0},{0,1,2,3},{0,0,1,1},{0,1,2,2},{2,0,1,2},{0,1,0,0},
				 {0,0,1,2},{1,1,0,1},{0,1,1,1},{0,1,2,0},{0,0,0,1},{0,1,1,2},
				 {1,0,1,0},{1,2,0,1},{0,0,1,1},{0,0,1,0},{1,0,1,2},{1,0,1,1},
				 {0,1,1,2} };
int dy[19][4] = { {0,1,2,3},{0,0,0,0},{0,1,0,1},{0,0,0,1},{0,1,1,1},{0,0,1,2},
				 {0,1,1,1},{0,1,2,2},{0,0,1,2},{0,0,0,1},{0,1,2,2},{0,0,1,1},
				 {0,1,1,2},{0,0,1,1},{0,1,1,2},{0,1,1,2},{0,1,1,1},{0,1,1,2},
				 {0,0,1,0} };

void sol()
{
	for (int x = 0; x < M; x++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int k = 0; k < 19; k++)
			{
				int temp = 0;
				
				int nx1 = x + dx[k][0], nx2 = x + dx[k][1], nx3 = x + dx[k][2], nx4 = x + dx[k][3];
				int ny1 = y + dy[k][0], ny2 = y + dy[k][1], ny3 = y + dy[k][2], ny4 = y + dy[k][3];
				
				if (0 <= max(max(nx1,nx2),max(nx3,nx4)) && max(max(nx1, nx2), max(nx3, nx4)) < M 
					&& 0 <= max(max(ny1, ny2), max(ny3, ny4)) && max(max(ny1, ny2), max(ny3, ny4))  < N)
					temp = map[nx1][ny1] + map[nx2][ny2] + map[nx3][ny3] + map[nx4][ny4];

				answer = (temp > answer) ? temp : answer;
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
}
int main()
{
	init();
	sol();

	cout << answer<<endl;

	return 0;
}
