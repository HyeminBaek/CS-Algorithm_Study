#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll N, K, Q,x,y;
vector<ll> last;
int getDepth(ll p, ll K) {
	int s = 0, e = last.size() - 1,d=-1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (last[m] >= p) {
			d = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	return d;
}
ll findPar(ll p, ll K) {
	int d = getDepth(p, K);
	if (d <= 1) return (ll)d;
	return last[d-2]+(p - last[d - 1]-1)/K+1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K >> Q;
	if (K > 1) {
		last.push_back(1);
		ll a = 1;
		while (last.back()<N) {
			a *= K;
			last.push_back(last.back()+a);		
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		if (K == 1) {
			ll ans = x - y;
			cout << (ans > 0 ? ans : -ans)<< "\n";
		}
		else {
			ll ans = 0;
			while (x != y) {
				
				if (x < y) {
					y = findPar(y, K);
				}
				else {
					x = findPar(x, K);
				}
				ans++;
			}
			cout << ans << "\n";
		}
		
	}
	return 0;
}