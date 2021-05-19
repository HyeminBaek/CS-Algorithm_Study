#include<iostream>

using namespace std;
int T, N, S, check[10001];
int main()
{
    for (int i = 0; i <= 10000; i++) {
        check[i] = -1;
    }
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        int sum = 0;
        check[0] = tc;
        for (int i = 0; i < N; i++) {
            scanf("%d", &S);

            for (int j = sum; j >= 0; j--) {
                if (check[j] == tc) {
                    check[j + S] = tc;
                }
            }
            sum += S;
        }
        int answer = 0;
        for (int i = 0; i <= sum; i++) {
            answer += (check[i] == tc);
        }
        printf("#%d %d\n", tc, answer);
    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}