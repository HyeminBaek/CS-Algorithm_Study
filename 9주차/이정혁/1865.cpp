#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int tc, N, M, W;

long long dist[503];
const long long INF = 987654321;
vector<string> result;

void solve() {
	cin >> N >> M >> W;
	vector<pair<int, long long>> load[503];
	memset(dist, INF, sizeof(dist));
	dist[1] = 0;
	for (int j = 0; j < M; j++) {
		int S, E, T;
		cin >> S >> E >> T;
		load[S].push_back({ E,T });
		load[E].push_back({ S,T });
	}
	for (int j = 0; j < W; j++) {
		int S, E, T;
		cin >> S >> E >> T;
		load[S].push_back({ E,-T });
	}
	bool possible = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < load[j].size(); k++) {
				if (dist[j] + load[j][k].second < dist[load[j][k].first]) {
					dist[load[j][k].first] = dist[j] + load[j][k].second;
					if (i == N && dist[load[j][k].first] != dist[1]) {
						possible = true;
					}
				}
			}
		}
	}
	if (possible) {
		result.push_back("YES");
	}
	else {
		result.push_back("NO");
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		solve();
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}
