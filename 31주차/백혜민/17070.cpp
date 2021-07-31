#include <iostream>
using namespace std;

/*
*  → 1		|  2	↘ 3  
*10:33~
*/
int N, answer;

int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

int arr[16][16];

void dfs(int x, int y, int prev)
{
	if (x == N - 1 && y == N - 1)
	{
		answer += 1; return;
	}

	int st = 0, ed = 1;
	if (prev == 0) ed = 2;
	else if (prev == 1) st = 1;
	
	for (int k = st; k < 3; k += ed)
	{
		int nx = x + dx[k], ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < N)
		{
			if (arr[nx][ny] == 0)
			{
				if (k == 2)
				{
					if (arr[nx - 1][ny] == 0 && arr[nx][ny - 1] == 0)
						dfs(nx, ny, k);
				}
				else
				{
					dfs(nx, ny, k);
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
			cin >> arr[i][j];
			if (arr[i][j]) arr[i][j] = -1;
		}
	}
}
int main()
{
	init();
	dfs(0, 1, 0); //가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로

	cout << answer;

	return 0;
}
