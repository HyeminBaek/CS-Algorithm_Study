#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int n, k;  // 전구10만, 반전10만
bool bit[100000];
bool fastbit[100000]; // 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> bit[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            fastbit[i] = 0 ^ bit[i];
        else
            fastbit[i] = bit[i - 1] ^ bit[i];
    }

    // 꺼져있으면 켜기
    int cnt = 0;
    for (int i = 0; i <= n - k; ++i) {
        if (fastbit[i]) {
            fastbit[i] ^= 1;
            fastbit[i + k] ^= 1;
            ++cnt;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (fastbit[i]) {
            cout << "Insomnia";
            return 0;
        }
    }
    cout << cnt;
    return 0;
}
