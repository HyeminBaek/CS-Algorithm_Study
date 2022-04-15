#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B;
ll solve(ll num) {
    ll ret = 0;
    for(int i = 1; i < 60; i++) {
        ll div_value = 1LL << i;
        ll sub_value = (div_value >> 1) - 1;
        ll Q = num / div_value;
        ll R = num % div_value;
        ret += (Q * (1LL<<(i-1)) + max(0LL, R-sub_value));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    ll right = solve(B);
    ll left = solve(A-1);
    cout << right - left << "\n";
}