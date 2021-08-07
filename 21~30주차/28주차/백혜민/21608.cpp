#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct pos
{
	int x, y, like, empty;
};
int N;
int arr[21][21];
int student[401][4];

map<int, pos> m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int sol()
{
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N)
				{
					for (int l = 0; l < 4; l++)
					{
						if (arr[nx][ny] == student[arr[i][j]][l]) cnt += 1;
					}
				}
			}

			switch (cnt)
			{
			case 1: answer += 1; break;
			case 2: answer += 10; break;
			case 3: answer += 100; break;
			case 4: answer += 1000; break;
			}
		}
	}

	return answer;
}
void place(int s)
{
	pos p = { -1,-1,-1,-1 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > 0) continue;

			int lcnt = 0, ecnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N)
				{
					if (arr[nx][ny] == 0) ecnt += 1;
					else
					{
						if (arr[nx][ny] == student[s][0] || arr[nx][ny] == student[s][1] ||
							arr[nx][ny] == student[s][2] || arr[nx][ny] == student[s][3])
							lcnt += 1;
					}
				}
			}
			
			if (p.like < lcnt)
			{
				p.like = lcnt, p.empty = ecnt, p.x = i, p.y = j;
			}
			else if (p.like == lcnt)
			{
				if (p.empty < ecnt)
				{
					p.empty = ecnt, p.x = i, p.y = j;
				}
			}
		}
	}

	arr[p.x][p.y] = s;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N*N; i++)
	{
		int x; cin >> x;

		for (int j = 0; j < 4; j++)
		{
			cin >> student[x][j];
		}

		place(x);
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}
