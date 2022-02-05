#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Edge {
	int a, b;
	ll c;
};
int N, M, par[100010], cnt = 0, d[100010];
Edge edge[500050];
ll ans = 0;
int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

bool merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;
	if (d[pa] >= d[pb]) {
		d[pa] += (d[pa] == d[pb]);
		par[pb] = pa;
	}
	else {
		par[pa] = pb;
	}
	return true;
}

bool compEdge(const Edge& a, const Edge& b) {
	return a.c < b.c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		par[i] = i;
		d[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].c;
	}
	sort(edge, edge + M, compEdge);
	
	for (int i = 0; i < M; i++) {
		if (merge(edge[i].a, edge[i].b)) cnt++;
		else ans += edge[i].c;
	}
	if (cnt != N - 1) ans = -1;
	cout << ans << "\n";
	return 0;
}