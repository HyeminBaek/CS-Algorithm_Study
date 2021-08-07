#include<iostream>
#include<list>
using namespace std;
typedef list<int>::iterator ITER;
struct Belt {
	int A;
	bool robot;
};
Belt belt[200];
int N, K,rn,ans;
list<int> robotlist;
int Retidx(int pos);
int Retpos(int idx);
void RobotMove();
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < 2*N; i++) {
		scanf("%d", &belt[i].A);
		belt[i].robot = false;
	}
	rn = 0;
	ans = 0;
	while (K > 0) {
		ans++;
		RobotMove();
		
		
	}
	printf("%d\n", ans);

	return 0;
}
int Retidx(int pos) {
	return (2*N+pos - rn) % (2 * N);
}
int Retpos(int idx) {
	return (2 * N + idx+ rn) % (2 * N);
}
void RobotMove() {
	//1¹ø
	int outidx = Retidx(N - 1);
	belt[outidx].robot = false;
	robotlist.remove(outidx);
	rn++;
	rn %= (2 * N);
	outidx = Retidx(N - 1);
	belt[outidx].robot = false;
	robotlist.remove(outidx);
	
	//2¹ø
	for (ITER iter = robotlist.begin(); iter != robotlist.end(); iter++) {
		int idx = *iter;
		int pos = Retpos(idx);
		int nextidx = (idx + 1) % (2 * N);
		int nextpos = (pos + 1) % (2 * N);
		if (!belt[nextidx].robot && pos != N - 1 &&belt[nextidx].A>=1) {
			belt[nextidx].robot = true;
			belt[nextidx].A--;
			belt[idx].robot = false;
			*iter = nextidx;
			if (belt[nextidx].A == 0) {
				K--;
			}
		}
	}
	
	//3¹ø
	int inidx = Retidx(0);
	if (belt[inidx].A != 0) {
		belt[inidx].robot = true;
		belt[inidx].A--;
		if (belt[inidx].A == 0) {
			K--;
		
		}
		robotlist.push_back(inidx);
	}
}