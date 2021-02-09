#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int A, B; //부모 노드 찾아야 할 말단 노드
vector<int> AParent;
vector<int> BParent;
vector<int> v[10001];
bool visited[10001];

void dfs(int x,bool AorB)//A일경우 0,AParent에 저장
{
	if (!AorB) AParent.push_back(x);
	else BParent.push_back(x);

	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (!visited[next])
		{
			visited[next] = true;
			dfs(next, AorB);
		}
	}
}
int find()
{
	for (int i = 0; i < AParent.size(); i++)
	{
		for (int j = 0; j < BParent.size(); j++)
		{
			if (AParent[i] == BParent[j])
				return AParent[i];
		}
	}
}
void init()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++)
		v[i].clear();
	AParent.clear(); BParent.clear();

	for (int i = 0; i < n - 1; i++)
	{
		int x, y; cin >> x >> y;
		v[y].push_back(x);
	}
	cin >> A >> B;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		init();
		memset(visited, false, sizeof(visited));	dfs(A, 0);
		memset(visited, false, sizeof(visited));	dfs(B, 1);

		cout << find() << endl;
	}

	return 0;
}
