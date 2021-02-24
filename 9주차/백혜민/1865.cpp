#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, W;
vector<pair<int,int>> v[501];
int dist[501];

void bellmanford()
{
	bool flag = false; 
	dist[1] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				int next = v[j][k].first, val = v[j][k].second;
				if (dist[j] != 100000000 && dist[next] > dist[j] + val)
				{
					dist[next] = dist[j] + val; 
					if (i == N - 1) flag = true;
				}
			}
		}
	}
	if (flag) cout << "YES\n";
	else cout << "NO\n";
}
void init()
{
	cin >> N >> M >> W;

	for (int i = 1; i <= N; i++)
		v[i].clear();
	for (int i = 0; i < M; i++)
	{
		int S, E, T; cin >> S >> E >> T;
		v[S].push_back({ E,T });
		v[E].push_back({ S,T });
	}
	for (int i = 0; i < W; i++)
	{
		int S, E, T; cin >> S >> E >> T;
		v[S].push_back({ E,-T });
	}
	memset(dist, 100000000, sizeof(dist));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (t; t > 0; t--)
	{
		init();
		bellmanford();
	}

	return 0;
}
