#include<iostream>

using namespace std;
int T, D, L, N;
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d%d%d", &D, &L, &N);
        printf("#%d %d\n", tc, D * N + D / 100 * L * (N * (N - 1)) / 2);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
