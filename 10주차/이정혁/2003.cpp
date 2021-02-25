#include<iostream>
#include<vector>

using namespace std;

int N, M, result;
vector<int> v;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += v[j];
			if (sum == M) {
				result++;
				break;
			}
			else if (sum > M) {
				break;
			}
		}
	}
}
int main(void) {
	init();
	solve();
	cout << result;
	return 0;
}
