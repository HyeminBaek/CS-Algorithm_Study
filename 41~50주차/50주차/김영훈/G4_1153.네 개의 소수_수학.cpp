#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
unordered_set<int> uset;
vector<int> ans;
int N;
bool isPrime[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= N; i++) {
		if (isPrime[i] == true) {
			uset.insert(i);
			for (int j = i * 2; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
	if (N < 8) {
		ans.push_back(-1);
	}
	else {
		ans.push_back(2 + N % 2);
		ans.push_back(2);
		N -= 4 + (N % 2);
		for (auto it = uset.begin(); it != uset.end(); it++) {
			if (uset.count(N - *it) > 0) {
				ans.push_back(*it);
				ans.push_back(N - *it);
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}