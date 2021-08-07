#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
int N, M,p,a,b;
ll C[100000], t;
vector<pli> adjlist[100000];

struct compare {
	bool operator()(pli p1, pli p2) {
		return p1.first > p2.first;
	}
};
priority_queue<pli,vector<pli>,compare> pq;
bool visit[100000];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &C[i]);
		visit[i] = false;
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		scanf("%d%d%lld", &a, &b, &t);
		adjlist[a - 1].push_back(pli(t,b-1));
		C[b - 1] += t;
	}
	for (int i = 0; i < N; i++) {
		pq.push(pli(C[i], i));
	}
	ll answer=0;
	while (M>0) {
		pli t = pq.top();
		pq.pop();
		if (visit[t.second]) continue;
		visit[t.second] = true;
		answer = answer<t.first?t.first:answer;
		M--;
		for (int i = 0; i < adjlist[t.second].size(); i++) {
			pli edge = adjlist[t.second][i];
			if (!visit[edge.second]) {
				C[edge.second] -= edge.first;
				pq.push(pli(C[edge.second], edge.second));
			}
		}
	}
	printf("%lld\n", answer);
	return 0;
}