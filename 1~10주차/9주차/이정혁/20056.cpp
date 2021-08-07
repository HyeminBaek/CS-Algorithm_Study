#include<iostream>
#include<vector>

using namespace std;

typedef struct fireball {
	int x;
	int y;
	int mass;
	int speed;
	int dir;
}fireball;

int N, M, K, result;
int movement[8][2] = { {0, -1}, {1, -1}, {1, 0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1} };

vector<fireball> arr[51][51];
vector<fireball> ball;

void init() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		ball.push_back({ r,c,m,s,d });
		arr[r][c].push_back({ r,c,m,s,d });
	}
}
void clear_arr() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j].clear();
		}
	}
}
void fireball_move() {
	for (int i = 0; i < ball.size(); i++) {
		int nx = ball[i].x + movement[ball[i].dir][1] * ball[i].speed;
		int ny = ball[i].y + movement[ball[i].dir][0] * ball[i].speed;
		if (nx < 1) {
			while (1) {
				if (nx >= 1) {
					break;
				}
				nx += N;
			}
		} 
		if (ny < 1) {
			while (1) {
				if (ny >= 1) {
					break;
				}
				ny += N;
			}
		}
		if (nx > N) {
			while (1) {
				if (nx <= N) {
					break;
				}
				nx -= N;
			}
		}
		if (ny > N) {
			while (1) {
				if (ny <= N) {
					break;
				}
				ny -= N;
			}
		}
		arr[nx][ny].push_back({ nx,ny, ball[i].mass, ball[i].speed, ball[i].dir }); // 이동한 값 저장
	}
}

void add() {
	vector<fireball> temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].size() == 1) { // 1개 들어있다면 그대로 삽입
				temp.push_back(arr[i][j][0]);
			}
			else if (arr[i][j].size() > 1) { // 2개 이상일 때
				int mass = 0;
				int speed = 0;
				int cnt = arr[i][j].size();

				bool even = false;
				bool odd = false;
				for (int k = 0; k < arr[i][j].size(); k++) { // mass, speed는 들어있는 것들의 총합, 들어있는 dir이 even인지 odd인지 판별
					mass += arr[i][j][k].mass;
					speed += arr[i][j][k].speed;
					if (arr[i][j][k].dir % 2) even = true;
					else odd = true;
				}
				if (mass / 5 == 0) continue; // 질량이 0 이라면 안넣어 줘도 됨
				if (even && odd) { // 짝 홀이 모두 들어있다면
					temp.push_back({ i,j,mass / 5,speed / cnt,  1 });
					temp.push_back({ i,j,mass / 5,speed / cnt,  3 });
					temp.push_back({ i,j,mass / 5,speed / cnt,  5 });
					temp.push_back({ i,j,mass / 5,speed / cnt,  7 });
				}
				else { // 홀수나 짝수만 존재 한다면
					temp.push_back({ i,j,mass / 5,speed / cnt,  0 });
					temp.push_back({ i,j,mass / 5,speed / cnt,  2 });
					temp.push_back({ i,j,mass / 5,speed / cnt,  4 });
					temp.push_back({ i,j,mass / 5,speed / cnt,  6 });
				}
			}
		}
	}
	ball = temp;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	for (int i = 0; i < K; i++) {
		clear_arr();
		fireball_move();
		add();
	}
	for (int i = 0; i < ball.size(); i++) {
		result += ball[i].mass;
	}
	cout << result;
	return 0;
}
