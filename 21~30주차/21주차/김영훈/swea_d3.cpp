#include<iostream>

using namespace std;
int T;
bool check[101];
int main()
{

    for (int i = 1; i <= 100; i++) {
        check[i] = false;
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            check[i * j] = true;
        }
    }
    scanf("%d", &T);
    int N;
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        printf("#%d %s\n", tc, (check[N] ? "Yes" : "No"));

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
