#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct s
{
	int x; int y;
};
int N, M;
long long gas;
int map[21][21];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

vector<pair<int, int>> p[401]; //승객은 최대 400명
vector<int> over;//이미 처리가 된 승객 저장용

int bfs(int sx, int sy, int ex, int ey)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });

	int visited[21][21];
	memset(visited, -1, sizeof(visited));
	visited[sx][sy] = 0;

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		if (x == ex && y == ey)
		{
			return visited[x][y];
		}
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] == 0 && visited[nx][ny] == -1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	return -1;
}
int findP(int x, int y) //최단 경로인 손님 찾기
{
	vector<pair<pair<int, int>, pair<int, int>>> pq; //최단거리,행,열,손님번호

	for (int i = 1; i <= M; i++)
	{
		if (find(over.begin(), over.end(), i) != over.end()) continue; //이미 승객이 처리되었으면
		int result = bfs(x, y, p[i][0].first, p[i][0].second);

		if (result == -1) return -1;
		pq.push_back({ { result,p[i][0].first },{ p[i][0].second,i } });
	}

	sort(pq.begin(), pq.end());

	return pq.front().second.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> gas;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	int taxi_x, taxi_y; cin >> taxi_x >> taxi_y;
	taxi_x--; taxi_y--;
	map[taxi_x][taxi_y] = -1;//택시는 맵 상에서 -1로 표시할 거임

	for (int i = 1; i <= M; i++)
	{
		int p_sx, p_sy, p_ex, p_ey; cin >> p_sx >> p_sy >> p_ex >> p_ey;

		p[i].push_back({ p_sx - 1,p_sy - 1 }); p[i].push_back({ p_ex - 1,p_ey - 1 });
	}

	for (int i = 0; i<M; i++)
	{
		//가스가 다 떨어진 경우
		if (gas < 0) break;

		//최단 거리 손님 찾기
		int idx = findP(taxi_x, taxi_y);

		//만약 택시가 못 가는 곳에 손님이 있다면
		if (idx < 0)
		{
			cout << -1;	 return 0;
		}

		gas -= bfs(taxi_x, taxi_y, p[idx][0].first, p[idx][0].second); // 연료 소모 

																	   //승객이 있는 곳으로 택시 이동
		map[taxi_x][taxi_y] = 0; map[p[idx][0].first][p[idx][0].second] = -1;
		taxi_x = p[idx][0].first; taxi_y = p[idx][0].second;

		//택시가 목적지까지 감
		int temp = bfs(taxi_x, taxi_y, p[idx][1].first, p[idx][1].second);
		//택시가 목적지까지 못가거나 가다가 연료가 바닥남
		if (temp == -1 || gas < temp)
		{
			cout << -1; return 0;
		}
		gas -= temp;
		gas += (2 * temp);

		over.push_back(idx);//목적지까지 간 승객을 저장함

							//목적지로 택시 이동
		map[taxi_x][taxi_y] = 0; map[p[idx][1].first][p[idx][1].second] = -1;
		taxi_x = p[idx][1].first; taxi_y = p[idx][1].second;
	}

	if (over.size() == M)	cout << gas;
	else cout << -1;

	return 0;
}
