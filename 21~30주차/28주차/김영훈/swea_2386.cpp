#include<iostream>
#include<set>
using namespace std;
int T, N, A;
set<int> sheet;
int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        sheet.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", &A);
            if (sheet.count(A) == 0) {
                sheet.insert(A);
            }
            else {
                sheet.erase(A);
            }
        }
        printf("#%d %d\n", tc, sheet.size());
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}