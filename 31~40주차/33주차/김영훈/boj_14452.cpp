/*
소들은 순서대로 들어감

시간 T안에 모든 소들이 춤을 끝낼 수 있는 가장 작은 무대크기 K를 구하는 것

K=N일 때 모든 소가 춤을 끝낸다는건 보장됨(d(i) <= T)
*/


#include<iostream>
#include<queue>
using namespace std;
int N, T,d[10000];


struct comp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int getT(int k) {
	priority_queue<int, vector<int>, comp> pq;
	int time = 0;
	for (int i = 0; i < N; i++) {
		while(pq.size() >= k) {
			time = pq.top();	
			pq.pop();
		}
		pq.push(d[i] + time);

	}
	while (!pq.empty()) {
		time = pq.top();
		pq.pop();
	}

	return time;
}
int main() {
	
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d", &d[i]);
	}
	int s = 1, e = N,ans=N;
	while (s <= e) {
		int m = (s + e) / 2;
		int r = getT(m);
		if (r <= T) {
			ans = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}