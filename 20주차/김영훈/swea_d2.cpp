#include<iostream>

using namespace std;
int T, a, bit[3][9];
bool Search(int r, int c, int a) {
    int idx[3] = { r,c, (r / 3) * 3 + (c / 3) };
    for (int k = 0; k < 3; k++) {
        if ((bit[k][idx[k]] & (1 << a)) == 0) {
            bit[k][idx[k]] |= (1 << a);
        }
        else {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        bool f = true;
        for (int i = 0; i < 9; i++) {
            bit[0][i] = 0;
            bit[1][i] = 0;
            bit[2][i] = 0;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &a);
                if (f) {
                    f = Search(i, j, a);
                }
            }
        }
        printf("#%d %d\n", tc, f);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}