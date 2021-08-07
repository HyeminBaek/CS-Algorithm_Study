#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[101][101];

int sol()
{
	int dist[101][101];
	memset(dist, 1000000, sizeof(dist));

	priority_queue <pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{0,0} }); dist[0][0] = 0;

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!pq.empty())
	{
		int x = pq.top().second.first, y = pq.top().second.second; pq.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			/*
			이 부분에서 풀이를 참고해씀다.(https://huiung.tistory.com/110)
			처음엔 v[x][y].push_back({i,j}); 느낌으로 저장했는데 에러가 떠서
			그래프 어떻게 접근해야 할 지 감이 안잡혀서 봤다.

			풀이 1. visited 배열을 두어, 방문하지 않았다면
			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) 조건을 만족하면 값 갱신하고 push
			-> 답은 나오지만 테스트케이스 2번 계속 1나옴, (1,1)에서 제대로된 min값 갱신이 안됨
			풀이 2. visited 배열을 두지 말자
			-> 그래도 1나옴

			한 번 더 풀이 참고
			풀이 3. 뭔가 pq를 greater로 안두고 가중치를 -로 잡았다
			->그래도 1나옴

   .		풀이 4. 알고보니 N,M을 바꿔서 입력받음, pq 원래대로 greater로 생각해봄

			*/
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (dist[nx][ny] > dist[x][y] + map[nx][ny])
				{
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					pq.push({ dist[nx][ny],{nx,ny} });
				}
			}
		}
	}

	return dist[N - 1][M - 1];
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	swap(N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}
