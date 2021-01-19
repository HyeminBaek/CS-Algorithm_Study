#include <iostream>
#include <vector>
using namespace std;

int R;
vector<int> v[100001];
int answer[100001];
bool visited[100001];

void dfs(int x)
{
	answer[x]++;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			visited[v[x][i]] = true;
			dfs(v[x][i]);
			answer[x] += answer[v[x][i]];
			visited[v[x][i]] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, Q; cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int x, y; cin >> x >> y;
		
		v[x].push_back(y); v[y].push_back(x);
	}
	visited[R] = true;
	dfs(R);

	for (Q; Q > 0; Q--)
	{
		int node; cin >> node;
		
		if (node == R) cout << N << "\n";
		else cout << answer[node] << "\n";
	}
	return 0;
}
