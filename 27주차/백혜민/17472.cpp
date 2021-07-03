#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct island
{
	int x, y, num;
};
int N, M, total;
int link[7][7],arr[10][10],uf[7];
bool visited[10][10];

vector<island> v;
vector<pair<int, pair<int, int>>> MST;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int unionFind(int a)
{
	if (a == uf[a]) return a;
	return uf[a] = unionFind(uf[a]);
}
bool Unionfind(int a, int b)
{
	a = unionFind(a);
	b = unionFind(b);

	if (a == b) return false;

	uf[b] = a;
	return true;
}
void sol()
{
	int answer = 0, cnt = 0;
	bool flag = true;
	bool* chk = new bool[total + 1];
	for (int i = 1; i <= total; i++) chk[i] = false;

	for (int i = 0; i < MST.size(); i++)
	{
		if (!chk[MST[i].second.first]) chk[MST[i].second.first] = true;
		if (!chk[MST[i].second.second]) chk[MST[i].second.second] = true;
	}
	for (int i = 1; i <= total; i++)
	{
		if (!chk[i])
		{
			flag = false; break;
		}
	}
	if (!flag||MST.empty() || MST.size()/2 < total - 1) cout << -1;
	else
	{
		int root = -1;
		for (int i = 0;; i++)
		{
			if (i<MST.size()&&Unionfind(MST[i].second.first, MST[i].second.second))
			{
				answer += MST[i].first;
				if (++cnt == total - 1) break;
			}
			if (i >= MST.size())
			{
				for (int i = 1; i <= total; i++)
				{
					if (root == -1) root = unionFind(uf[i]);
					else
					{
						if (root != unionFind(uf[i]))
						{
							root = -100; break;
						}
					}
				}
				if(root==-100) break;
			}
		}
		if (root == -100) cout << -1;
		else cout << answer;
	}
}
void find(int i, int j,int dir)
{
	queue<pair<pair<int, int>,int>> q;
	q.push({ {i,j},0 });

	int f = arr[i][j];
	
	while (!q.empty())
	{
		int x = q.front().first.first, y = q.front().first.second;
		int cnt = q.front().second; q.pop();

		int nx = x + dx[dir], ny = y + dy[dir];
		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (arr[nx][ny] == 0)
			{
				q.push({ {nx,ny},cnt + 1 });
			}
			else if (arr[nx][ny] != f)
			{
				if (cnt != 1)
				{
					link[f][arr[nx][ny]] = min(link[f][arr[nx][ny]], cnt);
					link[arr[nx][ny]][f] = min(link[arr[nx][ny]][f], cnt);
				}
				break;
			}
		}
	}
}
void bfs(int i,int j,int cnt)
{
	queue<pair<int, int>> q; q.push({ i,j });
	arr[i][j] = cnt; visited[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (!visited[nx][ny]&&arr[nx][ny]==-1)
				{
					visited[nx][ny] = true;
					arr[nx][ny] = cnt;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j]) arr[i][j] = -1;
		}
	}

	// 섬에 num을 매김
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j]&&arr[i][j] == -1)
			{
				bfs(i, j, cnt);
				cnt += 1;
			}
		}
	}
	total = cnt - 1;	
	for (int i = 1; i <= total; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			link[i][j] = 987654321;
		}
	}
	for (int i = 0; i < cnt; i++) uf[i] = i;
	// 다리 후보 찾기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k], ny = j + dy[k];

					if (0 <= nx && nx < N && 0 <= ny && ny < M)
					{
						if (arr[nx][ny] == 0)
						{
							find(i, j, k);
						}
					}
				}
			}
		}
	}
	
	//스패닝 트리 형성을 위한 작업
	for (int i = 1; i <= total; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			if (link[i][j] != 987654321)
			{
				MST.push_back({ link[i][j],{i,j} });
			}
		}
	}
	sort(MST.begin(), MST.end());
}
int main()
{
	init();
	sol();

	return 0;
}
