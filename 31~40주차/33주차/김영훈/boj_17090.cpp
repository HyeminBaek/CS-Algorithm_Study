#include<iostream>
#include<string>
#include<stack>
#include<utility>
using namespace std;
int N, M;
bool visit[500][500],isPossible[500][500];
string s[500];
typedef pair<int, int> pii;
pii getDir(char c);
void search(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s[i];
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
			isPossible[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				search(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += isPossible[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}

void search(int r, int c) {
	stack<pii> st;
	pii pos = pii(r, c);

	while (1) {
	
		if (pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= M || isPossible[pos.first][pos.second]) {
			while (!st.empty()) {
				pii t = st.top();
				st.pop();
				isPossible[t.first][t.second] = true;
			}
			break;
		}
		else if (visit[pos.first][pos.second]) {
			break;
		}



		visit[pos.first][pos.second] = true;
		st.push(pos);
		pii dir = getDir(s[pos.first][pos.second]);
		pos.first += dir.first;
		pos.second += dir.second;

	}
}
pii getDir(char c) {
	switch (c) {
	case 'U':
		return pii(-1, 0);
		break;
	case 'R':
		return pii(0, 1);
		break;
	case 'D':
		return pii(1, 0);
		break;
	default:
		return pii(0, -1);
		break;
	}
}