#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int len;
long long ans = LLONG_MIN;  // -1 * 9^10 = -34억
string s;

int calc(int a, int b, char op) {
    if (op == '+')
        a += b;
    else if (op == '-')
        a -= b;
    else if (op == '*')
        a *= b;

    return a;
}

void recur(int idx, int val) {
    if (idx >= len) {
        ans = max(ans, (long long)val);
        return;
    }

    char op = idx == 0 ? '+' : s[idx - 1];

    recur(idx + 2, calc(val, s[idx] - '0', op));
    if (idx + 2 < len) {  // num op, (num op, num) op
        int part = calc(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
        recur(idx + 4, calc(val, part, op));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> len >> s;
    recur(0, 0);

    cout << ans;
    return 0;
}
