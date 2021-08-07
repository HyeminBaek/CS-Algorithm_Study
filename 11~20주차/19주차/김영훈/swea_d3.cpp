#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct state {
    int bit;
    int last;
    int num;
    state(int bit, int last, int num) {
        this->bit = bit;
        this->last = last;
        this->num = num;
    }
};
int T, N, M, x, y, visit[(1 << 10)][10];
bool isadj[10][10];
queue<state> q;
int main()
{
    for (int i = 0; i < (1 << 10); i++) {
        for (int j = 0; j < 10; j++) {
            visit[i][j] = 0;
        }
    }
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d%d", &N, &M);
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                isadj[i][j] = false;
            }
        }
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &x, &y);
            isadj[x - 1][y - 1] = true;
            isadj[y - 1][x - 1] = true;
        }
        for (int i = 0; i < N; i++) {
            visit[(1 << i)][i] = tc;
            q.push(state((1 << i), i, 1));
        }
        while (!q.empty()) {
            state t = q.front();
            q.pop();
            answer = t.num > answer ? t.num : answer;
            for (int i = 0; i < N; i++) {
                int nbit = t.bit | (1 << i);
                if (nbit != t.bit && isadj[t.last][i] && visit[nbit][i] != tc) {
                    visit[nbit][i] = tc;
                    q.push(state(nbit, i, t.num + 1));
                }
            }
        }
        printf("#%d %d\n", tc, answer);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}