#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E, a, b, ct, oddEdgeNum[1000];
vector<int> adjlist[1000];
bool visit[1000];
void findSubGraph();

int main() {
	scanf("%d%d", &V, &E);
	
	for (int i = 0; i < E; i++) {
		scanf("%d%d", &a, &b);
		adjlist[a - 1].push_back(b - 1);
		adjlist[b - 1].push_back(a - 1);
	}
	
	findSubGraph();
	int ans = ct - 1;
	for (int i = 0; i < ct; i++) {
		ans += (oddEdgeNum[i] > 0 ? (oddEdgeNum[i] - 2) / 2 : 0);
	}

	printf("%d\n", ans);


	return 0;
}

void findSubGraph() {
	for (int i = 0; i < V; i++) {
		visit[i] = false;
	}
	ct = 0;
	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (!visit[i]) {
			oddEdgeNum[ct] = 0;
			visit[i] = true;
			q.push(i);
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				oddEdgeNum[ct] += (adjlist[t].size() % 2 == 1);
				for (int j = 0; j < adjlist[t].size(); j++) {
					int next = adjlist[t][j];
					if (!visit[next]) {
						visit[next] = true;
						q.push(next);
					}
				}	

			}
			ct++;
		}
	}

}