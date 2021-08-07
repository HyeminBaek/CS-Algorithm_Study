#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
vector<int> v1[10001];
vector<int> v2;
vector<int> v3;
bool visit[10001];
int node1, node2;
vector<int> result;
void init() {
	
}
void dfs1(int n) {
	v3.emplace_back(n);
	visit[n] = true;
	for (int i = 0; i < v1[n].size(); i++) {
		int next = v1[n][i];
		if (visit[next] == false) {
			dfs1(next);
		}
	}
}
void dfs2(int n) {
	v2.emplace_back(n);
	visit[n] = true;
	for (int i = 0; i < v1[n].size(); i++) {
		int next = v1[n][i];
		if (visit[next] == false) {
			dfs2(next);
		}
	}
}
int findparent() {
	for (int i = 0; i < v3.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v3[i] == v2[j]) {
				return v3[i];
			}
		}
	}
	return 0;
}
int main(void) {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int n;
		cin >> n;
		v3.clear();
		v2.clear();
		memset(visit, false, sizeof(visit));
		for (int k = 1; k < n; k++) {
			int num1, num2;
			cin >> num1 >> num2;
			v1[num2].emplace_back(num1);
		}
		cin >> node1 >> node2;
		dfs1(node1);
		memset(visit, false, sizeof(visit));
		dfs2(node2);
		result.emplace_back(findparent());
		for (int j = 0; j <= n; j++) {
			v1[j].clear();
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}
