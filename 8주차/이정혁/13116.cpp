#include<iostream>
#include<vector>

using namespace std;

int tc;
int n, m;
vector<int> v[1024];
void init() {
	for (int i = 1023; i >= 1; i--) {
		int x = i;
		while (x != 0) {
			v[i].push_back(x);
			x = x >> 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
	init();
	while (tc--) {
		int result = 0;
		cin >> n >> m;
		for (int i = 0; i < v[n].size(); i++) {
			for (int j = 0; j < v[m].size(); j++) {
				if (v[n][i] == v[m][j]) {
					result = v[n][i] * 10;
					break;
				}
			}
			if (result != 0) {
				break;
			}
		}
		cout << result <<'\n';
	}
	return 0;
}
