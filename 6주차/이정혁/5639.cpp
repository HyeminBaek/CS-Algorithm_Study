#include<iostream>

using namespace std;

int node[100001];
int idx;

void init() {
	int x;
	while (cin >> x) {
		if (x == EOF) break; //무한 입력주어질 때 파일이 끝나면 종료
		node[idx] = x;
		idx++;
	}
}

void solve(int x, int y) {
	if (x == y) {
		return;
	}

	int i = x + 1;

	while (1) {
		if (!(i < y && node[i] < node[x])) { // node[x]를 기준으로 작은게 왼쪽 큰게 오른쪽 이므로 서브트리를 나누는 기준 선정
			break;
		}
		i++;
	}
	solve(x + 1, i); // node[x]보다 값이 작은 것들 //왼쪽 먼저 출력해야하니 먼저 입력
	solve(i, y); // npde[x]보다 값이 큰 큰것들 // 그다음 오른쪽 출력
	cout << node[x] << '\n'; //루트를 제일 마지막에 출력
}
int main(void) {
	init();
	solve(0, idx);
	return 0;
}
