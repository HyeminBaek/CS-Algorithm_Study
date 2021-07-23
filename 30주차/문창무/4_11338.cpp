#include <iostream>
#include <queue>
#include <string>
using namespace std;

int t, q, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;  // 제일 큰 k개의 요소 xor연산
    while (t--) {
        cin >> q >> k;
        priority_queue<int> pq;
        int sum = 0;

        for (int i = 0; i < q; ++i) {
            string s;
            cin >> s;
            if (s == "insert") {
                int n;
                cin >> n;
                sum ^= n;
                pq.push(-n);

                if (pq.size() > k) {
                    sum ^= -pq.top();
                    pq.pop();
                }
            } else
                cout << sum << '\n';
        }
    }

    return 0;
}
