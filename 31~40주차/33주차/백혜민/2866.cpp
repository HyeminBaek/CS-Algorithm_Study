#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int R, C, answer;
vector<string> v;

bool chk(int mid) { //같은 것이 존재하면 true 리턴
	set<string> s;

	for (int j = 0;j < C;j++) {
		string tmp = "";
		for (int i = mid;i < R;i++) {
			tmp += v[i][j];
		}
		if (s.find(tmp) == s.end()) s.insert(tmp);
		else return true;
	}
	return false;
}
void binary() {
	int low = 0, high = R - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		bool result = chk(mid);

		if (result) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
			answer = (answer < mid) ? mid : answer;
		}
	}
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		string s; cin >> s;
		v.push_back(s);
	}		
}
int main() {
	init();
	binary();

	cout << answer;

	return 0;
}