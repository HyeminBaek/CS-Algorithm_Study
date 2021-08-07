#include<iostream>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
struct Fireball {
	int m;
	int s;
	int d;
	Fireball() {};
	Fireball(int m, int s, int d) {
		this->m = m;
		this->s = s;
		this->d = d;
	}
};
pii dir[8] = { pii(-1,0),pii(-1,1),pii(0,1),pii(1,1),pii(1,0),pii(1,-1),pii(0,-1),pii(-1,-1) };
int N, M, K,r,c,m,s,d;
vector<Fireball> map[50][50];
void Move();
void Divide();
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j].clear();
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d%d", &r, &c, &m, &s, &d);
		map[r - 1][c - 1].push_back(Fireball(m, s, d));
	}
	for (int i = 0; i < K; i++) {
		Move();
		Divide();
	}
	int ans = 0;
	for(int i=0; i<N; i++){
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				ans += map[i][j][k].m;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
void Move() {
	vector<Fireball> temp[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j].clear();
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				Fireball* f = &map[i][j][k];
				int nr = (N+i + dir[f->d].first * (f->s%N))%N;
				int nc = (N+j + dir[f->d].second * (f->s%N))%N;
				temp[nr][nc].push_back(*f);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}
}
void Divide() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() >= 2) {
				int checkbit = 0;
				int msum = 0, ssum = 0;
				for (int k = 0; k < map[i][j].size(); k++) {
					Fireball* f = &map[i][j][k];
					checkbit |= (1 << ((f->d % 2)));
					msum += f->m;
					ssum += f->s;
				}
				msum /= 5;
				ssum /= map[i][j].size();
				map[i][j].clear();
				if (msum == 0) 	continue;
				
				
				int d = 0;
				if (checkbit == 3) {
					d++;
				}
				while (d < 8) {
					map[i][j].push_back(Fireball(msum, ssum, d));
					d += 2;
				}
			}
		}
	}
}