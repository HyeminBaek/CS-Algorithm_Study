#include<iostream>

using namespace std;
int T, N, arr[10][10];
int main()
{
    scanf("%d", &T);
    arr[0][0] = 1;
    for (int i = 1; i < 10; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        printf("#%d\n", tc);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
