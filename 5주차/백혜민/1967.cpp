#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int len, dot;
vector<pair<int, int>> v[10001];
bool visited[10001];

void dfs(int x,int sum)
{
	visited[x] = true;

	if (sum > len)
	{
		len = sum; dot = x;
	}
	for (int k = 0; k < v[x].size(); k++)
	{
		if (!visited[v[x][k].first])
			dfs(v[x][k].first, sum + v[x][k].second);
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int p, c, val; cin >> p >> c >> val;
		v[p].push_back({ c,val });	v[c].push_back({ p,val });
	}
}
int main()
{
	init();

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(dot, 0);

	cout << len;

	return 0;
}
