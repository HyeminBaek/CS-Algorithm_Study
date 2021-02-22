#include <iostream>
using namespace std;

int N, M;
int dist[101][101];

void floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				dist[i][j] = (dist[i][j] > dist[i][k] + dist[k][j]) ? dist[i][k] + dist[k][j] : dist[i][j];
		}
	}
}
void print()
{
	/* 98%에서 틀려서 왜인지 했더니 방문 안되면 0처리해주어야 함*/
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == 99999999) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 99999999;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;

		dist[a][b] = (dist[a][b] > c) ? c : dist[a][b];
	}
}
int main()
{
	init();
	floyd();
	print();

	return 0;
}
