//https://www.acmicpc.net/problem/17071
#include <iostream>
#include <queue>
using namespace std;
const int max_num = 500001;
int visit[2][max_num];

int bfs(int N, int K)
{
	queue<int> que;
	que.push(N);
	visit[0][N] = 1;

	int epoch = 1;
	while (!que.empty()) {
		K += epoch;
		if (K >= max_num)
			return -1;
        if (visit[epoch % 2][K] == 1) {
			return epoch;
		}
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int cur = que.front();
			que.pop();
			for (int nx : {cur + 1, cur - 1, cur * 2}) {
				if (nx == K) {
					return epoch;
				}
				if (0 <= nx && nx < max_num && visit[epoch % 2][nx] == 0) {
					que.push(nx);
					visit[epoch % 2][nx] = 1;
				}				
			}
		}
		epoch++;
	}
	return -1;
}


int main()
{
	int N, K;
	cin >> N >> K;
	if (N == K) {
		cout << "0";
		return 0;
	} 
	cout << bfs(N, K);
	return 0;
}
