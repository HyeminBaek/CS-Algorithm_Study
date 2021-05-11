#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t, n, k;  // n100, k100

string solve(int idx) {
    switch (idx) {
        case 0:
            return "A+";
        case 1:
            return "A0";
        case 2:
            return "A-";
        case 3:
            return "B+";
        case 4:
            return "B0";
        case 5:
            return "B-";
        case 6:
            return "C+";
        case 7:
            return "C0";
        case 8:
            return "C-";
        case 9:
            return "D0";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            int mid, fin, as;
            cin >> mid >> fin >> as;
            v[i] = mid * 35 + fin * 45 + as * 20;
        }
        int target = v[k - 1];
        int targetIdx;

        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (v[i] == target) {
                targetIdx = n - i - 1;
                break;
            }
        }
        cout << '#' << i << ' ' << solve(targetIdx * 10 / n) << '\n';
    }

    return 0;
}
