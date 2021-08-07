#include<iostream>
using namespace std;
typedef long long ll;


int N, Q,answer[200000],acc[200001][6],lv;
char s1[30],s2[30],s3[30];
ll stime, etime,loglist[200000];
int Search(ll s, ll e, int lv);
int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < 6; i++) {
		acc[0][i] = 0;
	}
	for (int i = 0; i < N; i++) {
		scanf("%s%s", s1,s2);
		loglist[i] = 0;	
		for (int j = 0; j < 10; j++) {
			if (s1[j] >= '0' && s1[j] <= '9') {
				loglist[i] *= 10;
				loglist[i] += (s1[j] - '0');
			}
		}
		for (int j = 0; j <8; j++) {
			if (s2[j] >= '0' && s2[j] <= '9') {
				loglist[i] *= 10;
				loglist[i] += (s2[j] - '0');
			}
		}
		lv = s2[9] - '0';
		for (int j = 0; j < 6; j++) {
			acc[i+1][j] = acc[i][j] + (j == (lv - 1));
		}
	}
	for (int i = 0; i < Q; i++) {
		scanf("%s%s%s", s1, s2, s3);
		stime = 0;
		etime = 0;
		for (int j = 0; j < 10; j++) {
			if (s1[j] >= '0' && s1[j] <= '9') {
				stime *= 10;
				stime += (s1[j] - '0');
			}
		}
		for (int j = 0; j < 8; j++) {
			if (s2[j] >= '0' && s2[j] <= '9') {
				stime *= 10;
				stime += (s2[j] - '0');
			}
		}
		for (int j = 9; j <=18; j++) {
			if (s2[j] >= '0' && s2[j] <= '9') {
				etime *= 10;
				etime += (s2[j] - '0');
			}
		}
		for (int j = 0; j < 8; j++) {
			if (s3[j] >= '0' && s3[j] <= '9') {
				etime *= 10;
				etime += (s3[j] - '0');
			}
		}
		lv = s3[9] - '0';
		
		printf("%d\n", Search(stime, etime, lv));

	}
	return 0;
}
int Search(ll stime, ll etime, int lv) {
	int ret = 0;
	int s = 0, e = N-1,sidx=N,edix=-1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (loglist[m] >= stime) {
			sidx = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	s = 0, e = N-1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (loglist[m] <= etime) {
			edix = m;
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	for (int i = lv-1; i < 6; i++) {
		ret += acc[edix + 1][i] - acc[sidx][i];
	}
	return ret;
}