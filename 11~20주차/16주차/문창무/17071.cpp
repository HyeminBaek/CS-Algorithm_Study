#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 500000;
int n, k;  // 수빈, 동생
int check[MAX + 1][2];
// 수빈 x -> x-1, x+1, 2*x
// 동생: x -> x + i *(i+1) / 2 <i는 초>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    memset(check, -1, sizeof(check));
    queue<pair<int, int>> q;  // 수빈이 이동
    q.push({n, 0});

    while (!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        if (now < 0 || now > MAX) continue;
        if (check[now][time % 2] != -1) continue;

        check[now][time % 2] = time;
        q.push({now - 1, time + 1});
        q.push({now + 1, time + 1});
        q.push({now * 2, time + 1});
    }

    // 동생 이동
    int ans = -1;
    for (int i = 0; i < MAX; ++i) {  // 0초부터 최대 MAX초까지 확인
        int pos = k + i * (i + 1) / 2;
        if (pos > MAX) break;
        if (check[pos][i % 2] == -1) continue;

        if (check[pos][i % 2] <= i) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}
