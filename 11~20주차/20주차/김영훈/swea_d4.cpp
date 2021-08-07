#include<iostream>
using namespace std;
int map[100][100];
int Search(int start) {
    int r = 99;
    int c = start;
    while (r > 0) {
        if (c > 0 && map[r][c - 1] == 1) {
            while (c > 0 && map[r][c - 1] == 1) {
                c--;
            }
        }
        else if (c < 99 && map[r][c + 1] == 1) {
            while (c < 99 && map[r][c + 1] == 1) {
                c++;
            }
        }
        r--;
    }
    return c;
}
int main()
{
    int T;
    for (int tc = 1; tc <= 10; tc++) {
        scanf("%d", &T);
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        for (int i = 0; i < 100; i++) {
            if (map[99][i] == 2) {
                printf("#%d %d\n", tc, Search(i));
                break;
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}