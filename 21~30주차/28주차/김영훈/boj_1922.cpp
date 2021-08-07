#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
	int s,e, cost;
	Edge() {};
	Edge(int s, int e, int cost) {
		this->s = s;
		this->e = e;
		this->cost = cost;
	}
};
int N, M,a,b,c,par[1000],d[1000],cost[1000];
Edge edge[100000];
bool CompEdge(const Edge& e1, const Edge& e2);
int MST();
int Find(int k);
void Union(Edge e);
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		par[i] = i;
		d[i] = 1;
		cost[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		edge[i]=(Edge(a-1, b-1, c));
	}
	sort(edge, edge + M, CompEdge);
	printf("%d\n", MST());
	return 0;
}
bool CompEdge(const Edge& e1, const Edge& e2) {
	return e1.cost < e2.cost;
}
int MST() {
	for (int i = 0; i < M; i++) {
		Union(edge[i]);
	}	
	return *max_element(cost,cost+N);
}
int Find(int k) {
	if (par[k] == k) {
		return k;
	}
	return (par[k] = Find(par[k]));
}
void Union(Edge e) {
	int pa = Find(e.s);
	int pb = Find(e.e);
	if (pa == pb) return;
	if (d[pa] == d[pb]) {
		par[pb] = pa;
		cost[pa] += cost[pb]+e.cost;
		d[pa]++;
	}
	else if (d[pa] > d[pb]) {
		par[pb] = pa;
		cost[pa] += cost[pb]+ e.cost;
	}
	else {
		par[pa] = pb;
		cost[pb] += cost[pa]+ e.cost;
	}
}