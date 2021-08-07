#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fire
{
	int m, s, d;
};
int N, K;

vector<fire> arr[51][51];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

void sum()
{
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			while(!arr[i][j].empty())
			{
				answer += arr[i][j].back().m;
				arr[i][j].pop_back();
			}
		}
	}
	cout << answer;
}
void move()
{
	vector<pair<pair<int, int>, fire>> tmp;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			while (!arr[i][j].empty())
			{
				fire f = arr[i][j].back();
				arr[i][j].pop_back();

				int nx = i + f.s * dx[f.d], ny = j + f.s * dy[f.d];

				if (0 < nx && nx <= N && 0 < ny && ny <= N)
				{
					tmp.push_back({ {nx,ny},f });
				}
				else
				{
					if (nx > N)	nx %= N;
					if (ny > N) ny %= N;
					if (nx <= 0) nx = N - abs(nx) % N;
					if (ny <= 0) ny = N - abs(ny) % N;

					tmp.push_back({ {nx,ny},f });
				}
			}
		}
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		arr[tmp[i].first.first][tmp[i].first.second].push_back(tmp[i].second);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j].size() >= 2)
			{
				bool flag = true;
				int cnt = arr[i][j].size();

				fire f = arr[i][j].back(); arr[i][j].pop_back();
				while (!arr[i][j].empty())
				{
					f.m += arr[i][j].back().m;
					f.s+= arr[i][j].back().s;

					if (arr[i][j].back().d % 2 != f.d % 2) flag = false;

					arr[i][j].pop_back();
				}

				if ((int)(f.m / 5) > 0)
				{
					if (flag)
					{
						arr[i][j].push_back({ f.m / 5,f.s / cnt,0 });
						arr[i][j].push_back({ f.m / 5,f.s / cnt,2 });
						arr[i][j].push_back({ f.m / 5,f.s / cnt,4 });
						arr[i][j].push_back({ f.m / 5,f.s / cnt,6 });
					}
					else
					{
						arr[i][j].push_back({ f.m / 5,f.s / cnt,1 });
						arr[i][j].push_back({ f.m / 5,f.s / cnt,3 });
						arr[i][j].push_back({ f.m / 5,f.s / cnt,5 });
						arr[i][j].push_back({ f.m / 5,f.s / cnt,7 });
					}
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M >> K;

	for (M; M > 0; M--)
	{
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		arr[r][c].push_back({ m, s, d });
	}
}
int main()
{
	init();
	for (K; K > 0; K--)
	{
		move();
	}
	sum();

	return 0;
}
