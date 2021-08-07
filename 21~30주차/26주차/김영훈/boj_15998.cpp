#include<iostream>
using namespace std;
typedef long long ll;
int N;
ll a, b,M,money,minval;
ll GCD(ll a, ll b);
int main() {
	scanf("%d", &N);
	M = -1;
	money = 0;
	minval = 0;
	bool f = false;
	while (N--) {
		scanf("%lld%lld", &a, &b);
		if (money+a < 0) {
			if (M == -1) {
				M = -a + b - money;
			}
			else {
				M = GCD(M, -a + b - money);
			}
			minval = minval<b?b:minval;
		}
		else {
			if (money + a != b) {
				f = true;
			}
		}
		
		money = b;
	}
	if (M == -1 && !f) {
		M = 1;
	}
	else if (M <= minval || f) {
		M = -1;
	}
	printf("%lld\n", M);
	return 0;
}
ll GCD(ll a, ll b) {
	if (a > b) {
		ll t = a;
		a = b;
		b = t;
	}
	ll r;
	while (1) {
		r = b % a;
		if (r == 0) {
			break;
		}
		b = a;
		a = r;
	}
	return a;
}