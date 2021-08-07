
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, N, B, h;
bool visit[200001];
vector<int> v;
int main()
{
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        v.clear();
        scanf("%d%d", &N, &B);
        for (int i = 0; i <= 200000; i++) {
            visit[i] = false;
        }
        v.push_back(0);
        visit[0] = true;
        for (int i = 0; i < N; i++) {
            int sz = v.size();
            scanf("%d", &h);
            for (int j = 0; j < sz; j++) {
                int temp = v[j] + h;
                if (!visit[temp]) {
                    visit[temp] = true;
                    v.push_back(temp);

                }
            }
        }
        int ans = -1;
        for (int i = B; i <= 200000; i++) {
            if (visit[i]) {
                ans = i;
                break;
            }
        }
        printf("#%d %d\n", tc, ans - B);


    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}