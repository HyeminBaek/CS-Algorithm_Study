#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
각 정점별로 초기화해주면서 다익스트라를 돌리니 시간 초과 발생
다익스트라를 한 번만 쓰고 구하는 방법이 생각 안 나 찾아보니 플로이드와샬 알고리즘으로 문제가 분류되어 있음

플로이드 와샬: 정점 V개가 있고, 거리가 주어져있을 때 단 한 번의 시행으로 모든 정점 쌍 거리를 구한다
			   플로이드는 최단 경로를 DP 형태의 문제로 정의하고 풀어낸다
*/
int N, M; //방, 비밀통로
int dist[101][101];
vector<int> f;//친구 위치 저장용

int findIdx()
{
	int res = 987654321, ans = -1;
	for (int i = 1; i <= N; i++)
	{
		int tmp = 0;
		for (int j = 0; j < f.size(); j++)
			tmp += dist[i][f[j]];

		if (res > tmp)
		{
			res = tmp; ans = i;
		}
	}

	return ans;
}
void floydWarshall()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}
void init()
{
	cin >> N >> M;
	
	/* array initializing */
	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
			dist[i][j] = (i == j) ? 0 : 987654321;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c); //실수
	}

	f.clear();//실수

	int k; cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x; cin >> x;
		f.push_back(x);
	}
}
void sol()
{
	init();
	floydWarshall();
	cout << findIdx() << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--)
	{
		sol();
	}

	return 0;
}