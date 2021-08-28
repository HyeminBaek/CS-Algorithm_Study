#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N,R,a,b,d,l1=0,l2=0;
bool visit[200000];
vector<pii> adjlist[200000];
void Search(int n, int dist, bool f) {
	visit[n] = true;
	if (!f) {
		l1 = max(l1, dist);
		if (adjlist[n].size() >= 3-(n==R-1)) {
			f = true;
			dist = 0;
		}	
	}
	else {
		l2 = max(l2, dist);
	}
	for (int i = 0; i < adjlist[n].size(); i++) {
		pii* e = &adjlist[n][i];
		if (!visit[e->first]) {
			Search(e->first, dist + e->second, f);
		}
	}
}
int main() {
	scanf("%d%d", &N, &R);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &a, &b, &d);
		adjlist[a - 1].push_back(pii(b - 1, d));
		adjlist[b - 1].push_back(pii(a - 1, d));
		visit[i] = false;
	}
	visit[N - 1] = false;
	Search(R - 1, 0, false);
	printf("%d %d\n", l1, l2);

	return 0;
}