#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
string s;
ll n,max_ip,min_ip,ip;
void Print(ll bit);
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	max_ip = 0;
	min_ip = (static_cast<ll>(1)<<32);
	for (int i = 0; i < n; i++) {
		cin >> s;
		int num = 0;
		ip = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				ip<<= 8;
				ip += static_cast<ll>(num);
				num = 0;
			}
			else {
				num *= 10;
				num += (s[j] - '0');
			}
		}
		ip <<= 8;
		ip += num;
		max_ip = max(max_ip, ip);
		min_ip = min(min_ip, ip);
	}
	ll naddress = 0;
	ll nmask = 0;
	for (int i = 31; i >= 0; i--) {
		ll a = (min_ip & ((static_cast<ll>(1) << i)));
		ll b = (max_ip & ((static_cast<ll>(1) << i)));
		if (a != b) {
			break;
		}
	
		naddress |= a;
		nmask |= (static_cast < ll>(1) << i);
	}
	Print(naddress);
	Print(nmask);

	return 0;
}
void Print(ll bit) {
	int output[4] = { 0, };
	for (int i = 0; i<4; i++) {
		output[i] = bit % (1 << 8);
		bit >>= 8;
	}
	cout << output[3] << '.' << output[2] << '.' << output[1] << '.' << output[0] << "\n";
}