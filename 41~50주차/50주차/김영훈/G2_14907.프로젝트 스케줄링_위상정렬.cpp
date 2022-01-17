#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
struct comp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second > p2.second;
	}
};
string str;
vector<int> adjList[26];
int workTime[26],inDeg[26],t[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 26; i++) {
		workTime[i] = -1;
		t[i] = 0;
		inDeg[i] = 0;
	}
	while (getline(cin, str)) {
		int s= str[0] - 'A';
		int idx = 2;
		int ntime = 0;
		while (idx<str.size() && str[idx]!=' ') {
			ntime *= 10;
			if (str[idx] >= '0' && str[idx] <= '9') {
				ntime += str[idx] - '0';
			}
			idx++;
		}
		workTime[s] = ntime;

		idx++;
		while (idx < str.size()) {
			int e = str[idx] - 'A';
			adjList[s].push_back(e);
			inDeg[e]++;
			idx++;
		}

	}
	int ans = 0;
	priority_queue<pii, vector<pii>, comp> pq;
	for (int i = 0; i < 26; i++) {
		if (workTime[i] != -1 && inDeg[i] == 0) {
			pq.push(pii(i, 0));
		}
	}
	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();
		int ntime = workTime[now.first] + now.second;
		ans = max(ans,ntime);
		for (int i = 0; i < adjList[now.first].size(); i++) {
			int next= adjList[now.first][i];
			inDeg[next]--;
			t[next] = max(t[next], ntime);

			if (inDeg[next] == 0) {
				pq.push(pii(next, t[next]));
				
			}
		}


	}
	cout << ans << "\n";
	
	return 0;
}