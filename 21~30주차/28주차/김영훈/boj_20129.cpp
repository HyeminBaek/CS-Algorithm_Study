#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int op[4],k;
string s;
vector<ll> v;
void Parsing();
ll Operation(ll a, ll b, int op);
vector<ll> Result(int op);
int main() {
	ios::sync_with_stdio(false);
	v.clear();
	for (int i = 0; i < 4; i++) {
		cin >> k;
		op[k - 1] = i;
	}
	cin >> s;
	s += '.';
	Parsing();
	for (int i = 3; i >= 0; i--) {
		v = Result(op[i]);
		
	}
	printf("%lld\n", v[0]);
	return 0;
}
void Parsing() {
	ll val = 0;
	
	for (int i = 0; i <s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			val *= 10;
			val += (static_cast<ll>(s[i]) - '0');
		}
		else {
			v.push_back(val);
			val = 0;
			switch (s[i]) {
			case '+':
				v.push_back(0);
				break;
			case '-':
				v.push_back(1);
				break;
			case '*':
				v.push_back(2);
				break;
			case '/':
				v.push_back(3);
				break;
			}
		}
	}
	reverse(v.begin(), v.end());
}
ll Operation(ll a, ll b, int op) {
	ll ret = 0;
	switch (op) {
	case 0:
		ret = a + b;
		break;
	case 1:
		ret = a - b;
		break;
	case 2:
		ret = a * b;
		break;	
	case 3:
		ret = a / b;
		break;
	}
	return ret;
}
vector<ll> Result(int op) {
	vector<ll> ret;
	ret.clear();
	ret.push_back(v[0]);
	for (int i = 1; i < v.size(); i+=2) {
		if (v[i] == op) {
			ret.back() = Operation(ret.back(), v[i + 1], static_cast<int>(v[i]));
		}
		else {
			ret.push_back(v[i]);
			ret.push_back(v[i + 1]);
		}
		
	}


	return ret;
}
