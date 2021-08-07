#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> employee[100001];
int answer[100001];
bool visited[100001];

void dfs(int x)
{
	for (int i = 0; i < employee[x].size(); i++)
	{
		if (!visited[employee[x][i]])
		{
			visited[employee[x][i]] = true;
			answer[employee[x][i]] += answer[x];
			dfs(employee[x][i]);
			visited[employee[x][i]] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;

		if (x == -1) continue;

		employee[x].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int num, value; cin >> num >> value;

		answer[num] += value;
	}
	dfs(1);

	for (int i = 1; i <= n; i++)
		cout << answer[i] << " ";

	return 0;
}
