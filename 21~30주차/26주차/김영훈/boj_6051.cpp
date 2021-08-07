#include<iostream>
#include<utility>
#include<vector>
using namespace std;
typedef pair<char, int> pci;
int N,ans[80001],solve[80000],solve_sz;
pci query[80001];
vector<int> adjlist[80001];
void DFS(int k);
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin>>query[i].first;
		if (query[i].first != 's') {
			cin>>query[i].second;			
		}
		if (query[i].first == 't') {
			adjlist[query[i].second - 1].push_back(i);
		}
		else {
			adjlist[i - 1].push_back(i);
		}
	}
	solve_sz = 0;
	DFS(0);
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
void DFS(int k) {
	int del_problem=-1;
	switch (query[k].first) {
	case 'a':
		solve[solve_sz++] = query[k].second;
		break;
	case 's':
		if (solve_sz > 0) {
			del_problem = solve[solve_sz - 1];	
			solve_sz--;
		}
		break;
	}
	if (solve_sz > 0) {
		ans[k] = solve[solve_sz - 1];
	}
	else {
		ans[k] = -1;
	}
	for (int i = 0; i < adjlist[k].size(); i++) {
		int next = adjlist[k][i];
		DFS(next);
	}
	switch (query[k].first) {
	case 'a':
		solve_sz--;
		break;
	case 's':
		if (del_problem != -1) {
			solve[solve_sz++] = del_problem;
		}
		break;
	}
	
}