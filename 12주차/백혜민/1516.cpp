#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int indegree[501], time[501], answer[501];
vector<int> v[501];

void toplogical()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= N; i++)
	{
		int cur = q.front(); q.pop();
		
		for (int next : v[cur])
		{
			answer[next] = max(answer[next], answer[cur] + time[next]);
			if (--indegree[next] == 0) q.push(next);
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> time[i];
		answer[i] = time[i];

		int x;
		while (cin >> x)
		{
			if (x == -1) break;
			v[x].push_back(i); indegree[i]++;
		}
	}
}
void print()
{
	for (int i = 1; i <= N; i++)
		cout << answer[i] << "\n";
}
int main()
{
	init();
	toplogical();
	print();

	return 0;
}
