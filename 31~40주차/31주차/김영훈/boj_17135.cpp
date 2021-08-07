#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, M, D, a;
vector<pii> enemy;
int Abs(int a) {
	return a < 0 ? -a : a;
}
int getDist(pii p1, pii p2) {

	return Abs(p1.first - p2.first) + Abs(p1.second - p2.second);
}
int Play(int a, int b, int c) {
	int ret = 0,turn=0;
	vector<pii> enemylist[2];
	pii archer[3] = { pii(N,a),pii(N,b),pii(N,c) };
	enemylist[0] = enemy;
	enemylist[1].clear();
	while (enemylist[turn].size() > 0) {
		pii* target[3] = { NULL,NULL,NULL };
		for (int i = 0; i < enemylist[turn].size(); i++) {
			for (int j = 0; j < 3; j++) {
				if (target[j] == NULL) {
					target[j] = &enemylist[turn][i];
				}
				else {
					int nowdist = getDist(archer[j], *target[j]);
					int newdist = getDist(archer[j], enemylist[turn][i]);
					if (nowdist > newdist) {
						target[j] = &enemylist[turn][i];
					}
					else if (nowdist == newdist) {
						if (target[j]->second > enemylist[turn][i].second) {
							target[j] = &enemylist[turn][i];
						}
					}
				}
				
			}
		}
		for (int i = 0; i < 3; i++) {
			if (target[i] != NULL && getDist(archer[i], *target[i]) <= D) {
				target[i]->first = -1;
			}
		}
		for (int i = 0; i < enemylist[turn].size(); i++) {
			pii t = enemylist[turn][i];
			if (t.first == -1) {
				ret++;
			}
			else {
				if (t.first < N - 1) {
					enemylist[1 - turn].push_back(pii(t.first + 1, t.second));
				}
			}

		}
		enemylist[turn].clear();
		turn = 1 - turn;
	}
	

	return ret;

}
int main() {
	scanf("%d%d%d", &N, &M, &D);
	enemy.clear();
	for(int i=0; i<N; i++){
		for (int j = 0; j < M; j++) {
			scanf("%d", &a);
			if (a == 1) {
				enemy.push_back(pii(i, j));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			for (int k = j + 1; k < M; k++) {
				ans = max(ans, Play(i, j, k));
			}
		}
	}
	printf("%d", ans);
	return 0;

}