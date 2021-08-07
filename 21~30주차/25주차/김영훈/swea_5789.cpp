
#include<iostream>

using namespace std;
int box[1000], N, Q, L, R;
int main()
{
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d%d", &N, &Q);
        for (int i = 0; i < N; i++) {
            box[i] = 0;
        }
        for (int i = 1; i <= Q; i++) {
            scanf("%d%d", &L, &R);
            for (int j = L - 1; j <= R - 1; j++) {
                box[j] = i;
            }
        }
        printf("#%d ", tc);
        for (int i = 0; i < N; i++) {
            printf("%d ", box[i]);
        }
        printf("\n");
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}