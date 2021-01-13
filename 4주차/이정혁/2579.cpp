#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int stairs_cnt;
vector<int> stairs;
int d[10001];
void init() {
	cin >> stairs_cnt;
	for (int i = 0; i < stairs_cnt; i++) {
		int n;
		cin >> n;
		stairs.emplace_back(n);
	}
}

void dp() {
	d[0] = 0;
	d[1] = stairs[0];
	d[2] = stairs[0] + stairs[1];
	d[3] = max(d[1] + stairs[2], stairs[1] + stairs[2]);
	for (int i = 4; i <= stairs_cnt; i++) {
		d[i] = max(d[i - 3] + stairs[i - 2] + stairs[i - 1], d[i - 2] + stairs[i - 1]);
	}
	return;
}
int main(void) {
	init();
	dp();
	cout << d[stairs_cnt];
	return 0;
}
