
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int T, N;
ll arr[100000];
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%lld", &arr[i]);
        }

        sort(arr, arr + N);

        ll ans = 0;
        for (int i = 0; i < N; i++) {
            if (i % 3 != 2) {
                ans += arr[N - 1 - i];
            }
        }
        printf("#%d %lld\n", tc, ans);
    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}