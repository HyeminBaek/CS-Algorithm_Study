#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
양 옆의 선수들 중 차이가 작은 값을 찾아 더해가는 방식으로는 최솟값을 구할 수 가 없다
이유는 부전승을 마음대로 할 수 있기 때문이다.
한 토너먼트 씩 찾아가며 지워주여야 한다.
풀이 : 해당 랭킹 중 랭킹이 가장 낮은 사람이 먼저 지워져야 한다. 그렇지 않으면 올라 갈 수록 랭킹의 갭이 커져 값이 커진다.
즉 숫자가 가장 큰 놈을 양옆 중 차이가 작은놈으로 선택하여 지워 나가야 한다.
*/
int n, result;
vector<int> v;
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}
void solve() {
	vector<int>::iterator iter = v.begin();
	for (int i = 0; i < n - 1; i++) {
		int maximum = 0, idx;
		for (int j = 0; j < v.size(); j++) {
			if (maximum < v[j]) {
				idx = j;
				maximum = v[j];
			}
		}
		if (idx == 0) {
			result += abs(v[idx + 1] - v[idx]);
		}
		else if (idx == v.size() - 1) {
			result += abs(v[idx] - v[idx - 1]);
		}
		else {
			if (abs(v[idx] - v[idx - 1]) > abs(v[idx + 1] - v[idx])) {
				result += abs(v[idx + 1] - v[idx]);
			}
			else {
				result += abs(v[idx] - v[idx - 1]);
			}
			
		}
		v.erase(iter + idx, iter + idx + 1);
	}
}
/*
실 패 작
void solve() {
	int idx = 2;
	while (v.size() != 2) {
		vector<int> del;
		
		for (int i = 1; i < v.size() - 1; i += idx) {
			if (i == v.size() - 1) {
				break;
			}
			if (abs(v[i] - v[i - 1]) > abs(v[i + 1] - v[i])) {
				idx = 3;
				result += abs(v[i + 1] - v[i]);
				if (v[i + 1] < v[i]) {
					del.push_back(i);
				}
				else {
					del.push_back(i + 1);
				}
				if (i + idx == v.size() - 1) {
					break;
				}
			}
			else {
				idx = 2;
				result += abs(v[i] - v[i - 1]);
				if (v[i] < v[i - 1]) {
					del.push_back(i - 1);
				}
				else {
					del.push_back(i);
				}
				if (i + idx == v.size() - 1) {
					break;
				}
			}
		}
		vector<int>::iterator iter = v.begin();
		for (int i = del.size() - 1; i >= 0; i--) {
			v.erase(iter + del[i], iter + del[i] + 1);
		}
	}
}
*/
int main(void) {
	init();
	solve();
	cout << result;
	return 0;
}
