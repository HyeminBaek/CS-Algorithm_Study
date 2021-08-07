#include<iostream>
#include<vector>

using namespace std;

vector<long long> v[100005];
int n, m;
long long result[100005];
long long result2[100005];
bool visited[100005];
void init() {
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		if (a == -1) {
			continue;
		}
		v[i].emplace_back(a);
		v[a].emplace_back(i);
	}
	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		result[a] += b;
	}
}
void solution(long long x) { 
	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i]]) {
			visited[v[x][i]] = true;
			result[v[x][i]] += result[x];
			solution(v[x][i]);
			visited[v[x][i]] = false;
		}
	}
}
int main(void) {
	init();
	visited[1] = true;
	solution(1);
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
	return 0;
}
