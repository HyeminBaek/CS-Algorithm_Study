#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int INF = (1 << 30);
struct Info {
    int bit;
    int e;
    int dist;
    Info(int bit, int e, int dist) {
        this->bit = bit;
        this->e = e;
        this->dist = dist;
    }
};
int T, N, dist[10][10], dp[1 << 10][10];
pii s, e, c[10];
int ABS(int a) {
    return a < 0 ? -a : a;
}
int getDist(pii p1, pii p2) {
    return ABS(p1.first - p2.first) + ABS(p1.second - p2.second);
}
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = INF;
            }
        }

        scanf("%d%d%d%d", &s.first, &s.second, &e.first, &e.second);
        queue<Info> q;
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &c[i].first, &c[i].second);
            q.push(Info((1 << i), i, getDist(s, c[i])));
            dp[(1 << i)][i] = getDist(s, c[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = getDist(c[i], c[j]);
            }
        }


        while (!q.empty()) {
            Info t = q.front();
            q.pop();
            if (dp[t.bit][t.e] != t.dist) continue;

            for (int i = 0; i < N; i++) {
                int nbit = (t.bit | (1 << i));
                int ndist = t.dist + dist[t.e][i];
                if (t.bit != nbit && dp[nbit][i] > ndist) {
                    dp[nbit][i] = ndist;
                    q.push(Info(nbit, i, ndist));
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < N; i++) {
            int ndist = dp[(1 << N) - 1][i] + getDist(e, c[i]);
            ans = ans > ndist ? ndist : ans;
        }
        printf("#%d %d\n", tc, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}