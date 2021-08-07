#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

int N, M, result;
unsigned int compare = 0xfffffff;
vector<unsigned int> v;
vector<pair<int, char>> remember;
vector<int> answer;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		unsigned int data = 0x0000000;
		for (int j = 0; j < s.size(); j++) {
			data = data | (1 << (s[j] - 'a'));
		}
		v.push_back(data);
	}
	for (int i = 0; i < M; i++) {
		int t; char c;
		cin >> t >> c;
		remember.push_back({ t,c });
	}
}

void solve(int t, char c) {
	int a = c - 'a';
	result = 0;
	if (t == 1) {
		compare = compare & ~(1 << a);
	}
	else {
		compare = compare | (1 << a);
	}
	unsigned int aa = compare;
	for (int i = 0; i < v.size(); i++) {
		if ((compare & v[i]) == v[i]) {
			result++;
		}
	}
	answer.push_back(result);
}
int main(void) {
	init();
	for (int i = 0; i < M; i++) {
		solve(remember[i].first, remember[i].second);
	}
	for (int i = 0; i < M; i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}
