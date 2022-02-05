#include<iostream>
using namespace std;
typedef long long ll;
ll a, p;
bool isPrime(ll a) {
	ll k = 2;
	while (k * k <= a) {
		if (a % k == 0) {
			return false;
		}
		k++;
	}
	return true;
}

bool isFakePrime(ll p, ll a) {
	if (isPrime(p)) return false;
	//a^p%p=a ÀÎÁö
	ll e = p;
	ll b = a;
	ll c = 1;
	while (e > 0) {
		if (e % 2 == 1) {	
			c = (c * b) % p;
		}
		b = (b * b) % p;
		e /= 2;
	}
	return c==a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> p >> a;
	while (a != 0 && p != 0) {
		if (isFakePrime(p, a)) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
		cin >> p >> a;
	}
	return 0;
}