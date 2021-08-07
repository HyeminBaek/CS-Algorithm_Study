#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;  // 수의개수 11
vector<int> a(11);
vector<int> op(4);  // +-*/
vector<int> permu;  // permutation

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }
    for (int i = 0; i < 4; ++i) {  // +-*/
        for (int j = 0; j < op[i]; ++j) {
            permu.push_back(i);
        }
    }

    int min_ans = 1e9;
    int max_ans = -1e9;
    do {
        int first = a[0];

        for (int i = 0; i < n - 1; ++i) {
            int second = a[i + 1];
            if (permu[i] == 0)
                first += second;
            else if (permu[i] == 1)
                first -= second;
            else if (permu[i] == 2)
                first *= second;
            else if (permu[i] == 3)
                first /= second;
        }
        min_ans = min(min_ans, first);
        max_ans = max(max_ans, first);
    } while (next_permutation(permu.begin(), permu.end()));

    cout << max_ans << '\n'
         << min_ans;

    return 0;
}
