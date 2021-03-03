#include <iostream>
using namespace std;

int N, answer;
int map[500][500];

void spread(int x, int y, int dir)
{
	int tx[4][10] = { { -2,-1,-1,-1,0,1,1,1,2,0 },{-1,-1,0,0,0,0,1,1,2,1},{-2,-1,-1,-1,0,1,1,1,2,0},{1,1,0,0,0,0,-1,-1,-2,-1} };
	int ty[4][10] = { { 0,-1,0,1,-2,-1,0,1,0,-1 },{-1,1,-2,-1,1,2,-1,1,0,0},{0,-1,0,1,2,-1,0,1,0,1},{-1,1,-2,-1,1,2,-1,1,0,0} };
	int val[4][9] = { { 2,10,7,1,5,10,7,1,2 },{1,1,2,7,7,2,10,10,5},{2,1,7,10,5,1,7,10,2},{1,1,2,7,7,2,10,10,5} };
	int total = 0;

	for (int k = 0; k < 10; k++)
	{
		int nx = x + tx[dir][k], ny = y + ty[dir][k];
		int temp = 0;
		if (k < 9) temp = map[x][y] * val[dir][k] * 0.01; //이게 틀린 원인이였다

		if (0 <= nx && nx < N && 0 <= ny && ny < N)
		{
			if (k < 9) map[nx][ny] += temp;
			else map[nx][ny] += map[x][y] - total;
		}
		else
		{
			if (k < 9) answer += temp;
			else answer += map[x][y] - total;
		}
		total += temp;
	}

	map[x][y] = 0;
}
void tornado()
{
	int dx[] = { 0,1,0,-1 };
	int dy[] = { -1,0,1,0 };

	int dir = 0, num = 1;
	bool change = false;
	int x = N / 2, y = N / 2;

	while (1)
	{
		for (int i = 0; i < num; i++)
		{
			x += dx[dir]; y += dy[dir];
			spread(x, y, dir);

			if (x == 0 && y == 0) return;
		}
		//방향 전환
		if (!change) change = true;
		else
		{
			num++; change = false;
		}
		dir = (dir + 1) % 4;
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
			cin >> map[i][j];
	}
}
int main()
{
	init();
	tornado();

	cout << answer;

	return 0;
}
