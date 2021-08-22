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
struct Vertex {
	int indeg;
	vector<Edge> adjlist;
	vector<int> pre;
};
int n, m,s,e,d,t[10000];
Vertex v[10000];
bool visit[10000];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		v[i].indeg = 0;
		t[i] = -1;
		visit[i] = false;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &s, &e, &d);
		v[s-1].adjlist.push_back(Edge(e - 1, d));
		v[e - 1].indeg++;
		
	}
	scanf("%d%d", &s, &e);
	s--;
	e--;
	queue<int> q;
	q.push(s);
	t[s] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < v[now].adjlist.size(); i++) {
			Edge *e = &v[now].adjlist[i];
			
			if (t[e->e] < t[now] + e->d) {
				t[e->e] = t[now] + e->d;
				v[e->e].pre.clear();
				v[e->e].pre.push_back(now);
			}
			else if (t[e->e] == t[now] + e->d) {
				v[e->e].pre.push_back(now);
			}

			v[e->e].indeg--;
			if (v[e->e].indeg == 0) {
				q.push(e->e);
			}


		}


	}

	int edgenum = 0;
	q.push(e);
	visit[e] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		edgenum += v[now].pre.size();
		for (int i = 0; i < v[now].pre.size(); i++) {
			int next = v[now].pre[i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	printf("%d\n%d\n", t[e], edgenum);

	return 0;
}