#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, k;

bool count(ll x) {
    ll cnt = 0;
    for(int k = 1; k <= n; k++) {
        ll div = min(x / k, n);
        cnt += div;
    }

    return cnt >= k;
}

int main() {
    cin >> n >> k;
    ll lo = 0, hi = n*n+1;
    while(lo+1 < hi) {
        ll mid = (lo + hi) >> 1;
        if(count(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}
