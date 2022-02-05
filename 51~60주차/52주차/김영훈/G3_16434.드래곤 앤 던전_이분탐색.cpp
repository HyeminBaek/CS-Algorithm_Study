#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N;
ll atk,needHp[125000], room[125000][3];
bool isClear(ll maxHp) {
	ll nowHp = maxHp;
	for (int i = 0; i < N; i++) {
		if (room[i][0] == 2) nowHp = min(maxHp, nowHp + room[i][2]);
		else nowHp -= needHp[i];
		if (nowHp <= 0) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> atk;
	for (int i = 0; i < N; i++) {
		cin >> room[i][0] >> room[i][1] >> room[i][2];
	}

	for (int i = 0; i < N; i++) {
		if (room[i][0] == 2) atk += room[i][1];
		else needHp[i] = (ll)((room[i][2] - 1) / atk) * room[i][1];
	}

	ll s = 1;
	ll e = (ll)N * 1000000 * 1000000;
	ll ans = 0;
	while (s <= e) {
		ll m = (s + e) / 2;
		if (isClear(m)) {
			ans = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}