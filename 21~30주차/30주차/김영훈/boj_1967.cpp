#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Edge {
	int e, d;
	Edge(int e, int d) {
		this->e = e;
		this->d = d;
	}
};
const int INF = (1 << 30);
int n,a,b,c,dist[10000];
vector<Edge> adjlist[10000];

int searchTreeDiameter();
int searchEndPoint(int a);
void resetDistArr();
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adjlist[a - 1].push_back(Edge(b - 1, c));
		adjlist[b - 1].push_back(Edge(a - 1, c));
	}
	printf("%d\n", searchTreeDiameter());
	return 0;
}
int searchTreeDiameter() {
	resetDistArr();
	int a = searchEndPoint(0);
	resetDistArr();
	int b = searchEndPoint(a);
	return dist[b];
}
int searchEndPoint(int a) {
	dist[a] = 0;
	queue<int> q;
	q.push(a);
	int maxDist = 0;
	int maxDistVNum = 0;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (dist[t] > maxDist) {
			maxDist = dist[t];
			maxDistVNum = t;
		}
		for (int i = 0; i < adjlist[t].size(); i++) {
			Edge* e = &adjlist[t][i];
			if (dist[e->e] != -1) continue;
			dist[e->e] = dist[t] + e->d;
			q.push(e->e);		
		}
	}
	return maxDistVNum;
}
void resetDistArr() {
	for (int i = 0; i < n; i++) {
		dist[i] = -1;
	}
}