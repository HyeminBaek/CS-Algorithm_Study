#include<iostream>
#include<algorithm>
using namespace std;
int T, p, q, r, a, b, c, d;
int RetExDist(int x, int y) {
    return (x - p) * (x - p) + (y - q) * (y - q);
}
bool IsCircleInRect() {
    //x-p=r || p-x=r
    int min_x = p - r;
    int max_x = p + r;
    int min_y = q - r;
    int max_y = q + r;
    if (min_x<a || max_x>c || min_y<b || max_y>d) return false;
    return true;

}
bool IsRectInCircle() {
    // (a,c) (a,d) (b,c) (b,d)에 대해  (x-p)^2 + (y-q)^2<=r^2 일경우     
    int exdist = RetExDist(a, b);
    if (exdist > r * r) return false;
    exdist = RetExDist(a, d);
    if (exdist > r * r) return false;
    exdist = RetExDist(c, b);
    if (exdist > r * r) return false;
    exdist = RetExDist(c, d);
    if (exdist > r * r) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d%d%d%d%d%d%d", &p, &q, &r, &a, &b, &c, &d);
        char ans[3];
        ans[2] = '\0';
        if (IsRectInCircle()) {
            //1. 원안에 직사각형 = YN
            ans[0] = 'Y';
            ans[1] = 'N';

        }
        else if (IsCircleInRect()) {
            //2. 직사각형 안에 원이 포함 = NY
            ans[0] = 'N';
            ans[1] = 'Y';
        }
        else {
            //3. 두가지 케이스 아닌 경우 = YY
            ans[0] = 'Y';
            ans[1] = 'Y';
        }
        printf("#%d %s\n", tc, ans);


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}