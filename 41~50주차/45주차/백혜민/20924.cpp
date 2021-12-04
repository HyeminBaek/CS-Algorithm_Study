#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 200001;

int N, R, G, T;
vector<pair<int, int>> v[SIZE];
bool stem[SIZE];

int bfs(bool flag)//flag=false -> giga's length     flag=true -> leaf's length
{
	int stp = (!flag) ? R : T;
	queue<int> q; q.push(stp);

	if (!flag) stem[stp] = true;

	int visited[SIZE];
	for (int i = 0; i < SIZE; i++) visited[i] = -1;
	visited[stp] = 0;

	int maxv = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop();

		if (!flag && v[x].size() > 2)
		{
			G = x; return visited[x];
		}
		if (v[x].size() == 1)
			maxv = (maxv < visited[x]) ? visited[x] : maxv;

		for (int k = 0; k < v[x].size(); k++)
		{
			int nx = v[x][k].first;
			if (visited[nx] == -1)
			{
				if (!flag || (flag && !stem[nx]))
				{
					visited[nx] = visited[x] + v[x][k].second;
					q.push(nx);
				}
				if (!flag) stem[nx] = true;
			}
		}
	}

	return maxv;
}
void solution()
{
	int col = 0;

	if (v[R].size() == 1)
		col = bfs(false);
	else
	{
		G = R; stem[R] = true;
	}

	int maxv = 0;


	T = G;
	int result = bfs(true);

	cout << col << " " << result << "\n";
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, d; cin >> a >> b >> d;
		v[a].push_back({ b,d });
		v[b].push_back({ a,d });
	}
}
int main()
{
	init();
	solution();

	return 0;
}
