/*
  N=N+1

  N/2 ~N-1     패배






  13
  7~12 패
  3~6 승
  2 패
  1 승



8
4~7 패
2~3 승
1~1 패

6
3~5 패
1~2 승

11
6~10 패
3~5 승
2 패
1 승
*/


#include<iostream>
using namespace std;
typedef long long ll;
int T;
ll N;
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%lld", &N);
        bool f = true;
        ll s = N + 1, e = N + 1;
        while (s > 1) {
            if (f) {//패배 범위
                e = s - 1;
                s = s / 2 + (s % 2);
            }
            else {//승리 범위
                e = s - 1;
                s /= 2;
            }
            f = !f;
        }
        printf("#%d %s\n", tc, (!f ? "Bob" : "Alice"));
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
