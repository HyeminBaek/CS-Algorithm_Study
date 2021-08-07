#include<iostream>
using namespace std;
int T, N, use[200], a, b;
int main()
{

    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < 200; i++) {
            use[i] = 0;
        }
        int answer = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a, &b);
            int s = (a < b) ? a : b;
            int e = a + b - s;
            s = (s - 1) / 2;
            e = (e - 1) / 2;
            for (int j = s; j <= e; j++) {
                use[j]++;
            }
        }
        for (int i = 0; i < 200; i++) {
            answer = use[i] > answer ? use[i] : answer;
        }
        printf("#%d %d\n", tc, answer);
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}