#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, H, W, sr, sc, fr, fc;
int arr[1010][1010];
bool visited[1010][1010];
int movement[4][2] = { {0,1},{1,0}, {0,-1},{-1,0} };

vector<pair<int, int>> v;
queue<pair<int, int>> q;

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}
	cin >> H >> W >> sr >> sc >> fr >> fc;

	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i].first; j > v[i].first - H; j--) {
			if (j <= 0) {
				break;
			}
			for (int k = v[i].second; k > v[i].second - W; k--) {
				if (k <= 0) {
					break;
				}
				arr[j][k] = 987654321;
			}
		}
	}
}

void bfs() {
	q.push({ sr,sc });
	pair<int, int > current;
	visited[sr][sc] = true;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first + movement[i][0];
			int ny = current.second + movement[i][1];
			if (nx >= 1 && ny >= 1 && nx <= N - H + 1 && ny <= M - W + 1 && visited[nx][ny] == false && arr[nx][ny] != 987654321) {
				visited[nx][ny] = true;
				arr[nx][ny] = arr[current.first][current.second] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main(void) {
	init();
	bfs();
	if (sr == fr && sc == fc) {
		cout << 0;
		return 0;
	}
	if (!visited[fr][fc]) {
		cout << -1;
		return 0;
	}
	
	cout << arr[fr][fc];
	return 0;
}
