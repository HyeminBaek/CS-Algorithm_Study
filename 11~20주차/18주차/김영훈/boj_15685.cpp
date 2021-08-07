#include<iostream>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
pii dir[4] = { pii(1,0),pii(0,-1),pii(-1,0),pii(0,1) };
int N, x, y, d, g;
bool check[102][102];
void Check(int x, int y, int d) {

	check[x][y] = true;
	check[x + dir[d].first][y + dir[d].second] = true;
}
int main() {
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			check[i][j] = false;
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {

		scanf("%d%d%d%d", &x, &y, &d, &g);
		vector<int> v;
		v.push_back(d);
		Check(x, y, d);
		x += dir[d].first;
		y += dir[d].second;

		for (int j = 1; j <= g; j++) {

			for (int k = v.size() - 1; k >= 0; k--) {
				int nd = (v[k] + 1) % 4;
				Check(x, y, nd);
				x += dir[nd].first;
				y += dir[nd].second;
				v.push_back(nd);
			}
		}

	}
	int answer = 0;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			answer += (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1]);


		}
	}
	printf("%d\n", answer);
	return 0;
}
