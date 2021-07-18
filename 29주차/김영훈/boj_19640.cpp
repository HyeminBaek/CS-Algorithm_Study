#include<iostream>
#include<queue>
using namespace std;
struct info {
	int D;
	int H;
	int idx;
	int line;
	info() {}
	info(int D, int H, int idx,int line) {
		this->D = D;
		this->H = H;
		this->idx = idx;
		this->line = line;
	}
};
struct Compinfo {
	bool operator()(const info& i1, const info& i2) {
		if (i1.D != i2.D) {
			return i1.D < i2.D;
		}
		if (i1.H != i2.H) {
			return i1.H < i2.H;
		}
		return i1.line > i2.line;
	}
};
int N, M, K;
priority_queue<info, vector<info>, Compinfo> pq;
info ilist[100000];
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &ilist[i].D, &ilist[i].H);
		ilist[i].idx = i;
		ilist[i].line = i % M;
	}
	for (int i = 0; i < M; i++) {
		pq.push(ilist[i]);
	}
	int ans = 0;
	while (1) {
		info t = pq.top();
		pq.pop();
		if (t.idx == K) {
			break;
		}
		ans++;
		if (t.idx + M < N) {
			pq.push(ilist[t.idx + M]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
