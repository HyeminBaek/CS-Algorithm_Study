#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N;
int parent[50001][16];
int depth[50001];
vector<int> v[50001];

void makeTree(int cur)
{
	for (int next : v[cur])
	{
		if (depth[next] == -1)
		{
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			makeTree(next);
		}
	}
}
int sol(int u,int v)
{
	if (depth[u] < depth[v]) swap(u, v);
	int dif = depth[u] - depth[v];

	for (int j = 0; dif; j++)
	{
		if (dif % 2) u = parent[u][j];
		dif /= 2;
	}

	if (u != v)
	{
		for (int j = 15; j >= 0; j--)
		{
			if (parent[u][j] != -1 && parent[u][j] != parent[v][j])
			{
				u = parent[u][j], v = parent[v][j];
			}
		}
		u = parent[u][0];
	}

	return u;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	 
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int x, y; cin >> x >> y;
		v[x].push_back(y); v[y].push_back(x);
	}
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	makeTree(1);

	for (int j = 0; j < 15; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}
}
int main()
{
	init();
	int t; cin >> t;
	for (t; t > 0; t--)
	{
		int x, y; cin >> x >> y;
		cout << sol(x, y) << "\n";
	}

	return 0;
}
