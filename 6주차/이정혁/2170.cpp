#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, result;
vector<pair<int , int>> v;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
}

void solution() {
	result = v[0].second - v[0].first;
	long long maximum = v[0].second;
	for (int i = 1; i < N; i++) {
		if (v[i].first > maximum) {
			result += v[i].second - v[i].first;
			maximum = v[i].second;
		}
		else if (v[i].second > maximum) {
			result += v[i].second - maximum;
			maximum = v[i].second;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	solution();
	cout << result;
	return 0;
}
