#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int solve(vector<int>& a) {
    ll amount = 0;
    for (int money : a) {
        amount += money;
    }

    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < a.size(); i += 3) {
        if (i + 2 < a.size()) {
            amount -= a[i + 2];
        }
    }

    return amount;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << '#' << tc << ' ' << solve(a) << endl;
    }
    return 0;
}
