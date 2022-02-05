#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
const int INF = (1 << 30);
int T,N,M,dist[110][110],s,e,c,K,f[110];
vector<pii> adjList[110];
struct comp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second > p2.second;
	}
};

priority_queue<pii> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			adjList[i].clear();
		}
		for (int i = 0; i < M; i++) {
			cin >> s >> e >> c;
			adjList[s].push_back({ e,c });
			adjList[e].push_back({ s,c });
		}
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> f[i];
			for (int j = 1; j <= N; j++) {
				dist[f[i]][j] = INF;
			}
			dist[f[i]][f[i]] = 0;
			pq.push({ f[i],0 });
			while (!pq.empty()) {
				pii now = pq.top();
				pq.pop();
				if (now.second > dist[f[i]][now.first]) continue;
				for (int j = 0; j < adjList[now.first].size(); j++) {
					pii* edge = &adjList[now.first][j];
					int nDist = now.second + edge->second;
					if (nDist >= dist[f[i]][edge->first]) continue;
					dist[f[i]][edge->first] = nDist;
					pq.push({ edge->first,nDist });
				}
			}
		}
		int ans = -1;
		int maxDist = INF;
		for (int i = 1; i <= N; i++) {
			int nDist = 0;
			for (int j = 0; j < K; j++) {
				nDist += dist[f[j]][i];
			}
			if (maxDist > nDist) {
				maxDist = nDist;
				ans = i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}