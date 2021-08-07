#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, L;
ll pos[150000];
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &pos[i]);
		
	}

	sort(pos, pos + N);
	
	ll ans = 0,s=pos[0]-L,e=pos[0]+L;
	for (int i = 1; i < N; i++) {
		ll ns = pos[i] - L;
		ll ne = pos[i] + L;
		if (ns >= e) {
			s = ns;
			e = ne;
		}
		else if (ns < s) {
			ans += (e - s);
			s = e;
			e = ne;
		}
		else {
			ans += e - ns;
			s = e;
			e = ne;
		}

	}
	printf("%lld\n", ans);


	return 0;
}