#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
struct CityInfo {
    pii pos;
    int s;
};
int T, N, ct[1000], s[1000];
CityInfo cityinfo[1000];
int CompPii(pii a, pii b);
int ExDist(pii p1, pii p2);
int Find(int a);
int main()
{

    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            ct[i] = 0;
            s[i] = -1;
            scanf("%d%d%d", &cityinfo[i].pos.first, &cityinfo[i].pos.second, &cityinfo[i].s);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int exdist = ExDist(cityinfo[i].pos, cityinfo[j].pos);

                pii d1 = pii(cityinfo[j].s, exdist);
                if (CompPii(pii(cityinfo[i].s, 1), d1) < 0) {
                    if (s[i] == -1) {
                        s[i] = j;
                        ct[i] = 1;
                    }
                    else {
                        int c1 = s[i];
                        pii d2 = pii(cityinfo[c1].s, ExDist(cityinfo[i].pos, cityinfo[c1].pos));
                        int r = CompPii(d1, d2);
                        if (r == 0) {
                            ct[i]++;
                        }
                        else if (r > 0) {
                            ct[i] = 1;
                            s[i] = j;
                        }
                    }

                }
            }
        }
        printf("#%d ", tc);
        for (int i = 0; i < N; i++) {
            if (ct[i] == 0) {
                printf("K ");
            }
            else if (ct[i] == 1) {
                printf("%d ", Find(i) + 1);
            }
            else {
                printf("D ");
            }
        }
        printf("\n");
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int ExDist(pii p1, pii p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int CompPii(pii a, pii b) {
    int dif = a.first * b.second - b.first * a.second;
    if (dif == 0) {//a==b
        return 0;
    }
    else if (dif < 0) {//a가 b보다 작음
        return -1;
    }
    else {
        return 1;
    }
}
int Find(int a) {
    if (ct[a] != 1) return a;
    return s[a] = Find(s[a]);
}