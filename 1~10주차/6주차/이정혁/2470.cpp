#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> v;
int N;
long long result1, result2;
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long liquid;
		cin >> liquid;
		v.emplace_back(liquid);
	}
	sort(v.begin(), v.end());
}

void solve(int x) {
	int start = x + 1;
	int last = N - 1;
	while (start <= last) {
		int mid = (start + last) / 2;
		long long value = v[mid] + v[x];
		if (value == 0) {
			result1 = v[mid];
			result2 = v[x];
			break;
		}
		else if (value > 0) {
			last = mid - 1;
		}
		else {
			start = mid + 1;
		}
		if (abs(value) < abs(result1 + result2)) {
			result1 = v[mid];
			result2 = v[x];
		}
	}
}

int main(void) {
	init();
	result1 = v[0];
	result2 = v[(N - 1) / 2];
	if (N == 2) {
		cout << v[0] << ' ' << v[1];
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		solve(i);
		if (result1 + result2 == 0) {
			break;
		}
	}
	if (result1 > result2) {
		swap(result1, result2);
	}
	cout << result1 << ' ' << result2;
	return 0;
}
