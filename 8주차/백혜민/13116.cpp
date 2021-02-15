#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int parent[1024][11];
int depth[1024];
vector<int> v[1024];

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
int sol(int u, int v)
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
		for (int j = 10; j >= 0; j--)
		{
			if (parent[u][j] != -1 && parent[u][j] != parent[v][j])
				u = parent[u][j], v = parent[v][j];
		}
		u = parent[u][0];
	}

	return 10 * u;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 511; i++) //트리생성
	{
		v[i].push_back(2 * i);	v[i].push_back(2 * i + 1);
		v[2 * i].push_back(i);	v[2 * i + 1].push_back(i);
	}

	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;

	makeTree(1);

	for (int j = 0; j < 10; j++)
	{
		for (int i = 1; i <= 1023; i++)
		{
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}
}
int main()
{
	init();

	int T; cin >> T;
	for (T; T > 0; T--)
	{
		int u, v; cin >> u >> v;
		cout << sol(u, v) << "\n";
	}

	return 0;
}
