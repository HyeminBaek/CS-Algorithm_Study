#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Event {
	int type, pos, idx;
	Event() {}
	Event(int type, int pos, int idx) {
		this->type = type;
		this->pos = pos;
		this->idx = idx;
	}
};
int n, l, r;
Event e[20000];
bool isVisible[10000];
bool isEnqueued[10000];
bool compEvent(const Event& a, const Event& b) {
	return a.pos < b.pos;
}

struct CompIdx {
	bool operator()(const int& a, const int& b) {
		return a < b;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		isVisible[i] = false;
		isEnqueued[i] = false;
		cin >> l >> r;
		e[2 * i] = Event(0, l, i);
		e[2 * i + 1] = Event(1, r+1, i);
	}
	sort(e, e + 2 * n, compEvent);
	priority_queue<int, vector<int>, CompIdx> pq;

	for (int i = 0; i < 2 * n; i++) {
		if (e[i].type == 0) {
			isEnqueued[e[i].idx] = true;
			pq.push(e[i].idx);
		}
		else {
			isEnqueued[e[i].idx] = false;
		}
		if (i == 2 * n - 1 || e[i].pos != e[i + 1].pos) {
			while (!pq.empty() && !isEnqueued[pq.top()]) {
				pq.pop();
			}
			if (!pq.empty()) {
				isVisible[pq.top()] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += isVisible[i];
	}
	cout << ans << "\n";
	return 0;
}