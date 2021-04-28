#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
struct Edge {
	int s;
	int e;
	int k;
};
int N, M, s, e,par[100000],h[100000];
Edge elist[300000];
int Find(int a) {
	if (par[a] == a) {
		return a;
	}
	
	return (par[a] = Find(par[a]));
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) {
		return;
	}
	if (h[pa] > h[pb]) {
		par[pb] = pa;
	}
	else if (h[pa] < h[pb]) {
		par[pa] = pb;
	}
	else {
		par[pb] = pa;
		h[pa]++;
	}
}
bool compare(Edge e1, Edge e2) {
	return e1.k > e2.k;
}
int main() {
	scanf("%d%d%d%d", &N, &M,&s,&e);
	for (int i = 0; i < N; i++) {
		par[i] = i;
		h[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &elist[i].s, &elist[i].e, &elist[i].k);
	}
	sort(elist, elist + M,compare);
	int answer = 0;
	for (int i = 0; i < M; i++) {
		Union(elist[i].s - 1, elist[i].e - 1);
		if (Find(s - 1) == Find(e - 1)) {
			answer = elist[i].k;
			break;
		}
	}
	printf("%d\n", answer);
	return 0;
}
