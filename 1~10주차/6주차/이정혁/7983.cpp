#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, arr[1000002], maximum;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, t;
		cin >> d >> t;
		v.push_back({ t,d });
	}
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < n; i++) {
		arr[i] = v[i].first;
	}
}

void solution() {
	int idx = 0;
	int result = 0;
	for (int i = 0; i < n ; i++) {
		if (arr[i] - v[i].second > arr[i + 1]) {
			maximum = 0;
			result = arr[i] - v[i].second - arr[i + 1];
			maximum = max(maximum, result);
		}
		else {
			arr[i + 1] = arr[i] - v[i].second;
		}
		
	}
}

int main(void) {
	init();;
	solution();
	cout << maximum;
	return 0;
}
