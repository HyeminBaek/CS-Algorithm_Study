#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct CompData {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int T, Q, K,n;
string s;
void sol(int Q,int K);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> Q >> K;
		sol(Q, K);
	}
	return 0;
}
void sol(int Q, int K) {
	priority_queue<int, vector<int>, CompData> pq;
	int xorSum = 0;
	for (int i = 0; i < Q; i++) {
		cin >> s;
		if (s[0] == 'i') {
			cin >> n;
			xorSum ^= n;
			pq.push(n);
			while (pq.size() > K) {
				xorSum ^= pq.top();
				pq.pop();
			}
		}
		else {
			cout << xorSum << "\n";
		}
	}
}