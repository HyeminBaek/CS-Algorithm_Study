#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, S, P;
vector<int> v[328001];
int visited[328001];

void bfs()
{
	vector<int> root;
	queue<int> q; q.push(P);
	visited[P] = 0;
	
	while (!q.empty())
	{
		int x = q.front(); q.pop();

		if (root.size() >= 2) break;

		for (int k = 0; k < v[x].size(); k++)
		{
			int nx = v[x][k];

			if (visited[nx]==-1)
			{
				visited[nx] = visited[x] + 1;
				if (nx <= S) root.push_back(visited[nx]);

				q.push(nx);
			}
		}
	}

	cout << N - (root[0] + root[1] + 1);
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> S >> P;

	for (int i = 1; i < N; i++)
	{
		int A, B; cin >> A >> B;

		v[A].push_back(B);
		v[B].push_back(A);

		visited[i] = -1;
	}
	visited[N] = -1;
}
int main()
{
	init();
	bfs();

	return 0;
}
