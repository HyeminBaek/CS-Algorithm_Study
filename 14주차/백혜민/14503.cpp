#include <iostream>
using namespace std;

int N, M, d, answer;
int arr[51][51];//맵
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void swap(int x, int y)
{
	arr[x][y] = -1;
	answer++;
}
int left(int t)
{
	if (t == 0) return 3;
	else if (t == 1) return 0;
	else if (t == 2) return 1;
	else if (t == 3) return 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y;
	cin >> N >> M >> x >> y >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	while (1)
	{
		int t = d;
		t = left(t);

		if (arr[x][y] == 0) swap(x, y);

		if (arr[x + dx[t]][y + dy[t]] == 0)
		{
			d = t; x += dx[t]; y += dy[t];
			swap(x, y);
		}
		else
		{
			//4 방향 모두 청소 or 벽
			if (arr[x + 1][y] != 0 && arr[x - 1][y] != 0 && arr[x][y + 1] != 0 && arr[x][y - 1] != 0)
			{
				if (arr[x - dx[d]][y - dy[d]] == 1) break;
				else
				{
					x -= dx[d]; y -= dy[d];
				}
			}
			else
				d = t;
		}
	}
	
	cout << answer;

	return 0;
}
