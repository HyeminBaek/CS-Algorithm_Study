#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;
int N, K, n[100];
unordered_set<int> uset;
queue<int> q[110];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> n[i];
		q[n[i]].push(i);
	}
	for (int i = 0; i <= K; i++) {
		q[i].push(101);
	}
	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (uset.size() < N) {
			uset.insert(n[i]);
		}
		else {
			if (uset.count(n[i]) == 0) {
				int target = -1;
				for (auto iter = uset.begin(); iter != uset.end(); iter++) {
					if (target == -1 || q[target].front() < q[*iter].front()) {
						target = *iter;
					}				
				}
				ans++;
				uset.erase(target);
				uset.insert(n[i]);
			}
		}
		q[n[i]].pop();

	}
	cout << ans << "\n";
	return 0;
}