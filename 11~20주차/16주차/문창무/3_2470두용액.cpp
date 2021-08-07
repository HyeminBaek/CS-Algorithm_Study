#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n;  // 2~100000
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    int t1, t2;
    int ans = INT_MAX;

    while (left < right) {
        int sum = a[left] + a[right];
        if (abs(sum) < ans) {
            ans = abs(sum);
            t1 = left;
            t2 = right;
        }
        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << a[t1] << ' ' << a[t2] << endl;
    return 0;
}
