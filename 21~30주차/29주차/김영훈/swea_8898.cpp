#include<iostream>
#include<algorithm>
using namespace std;
int T, N, M, c1, c2, zpos1[500000], zpos2[500000];
bool CompZPos(const int& p1, const int& p2);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        cin >> c1 >> c2;

        for (int i = 0; i < N; i++) {
            cin >> zpos1[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> zpos2[i];
        }
        sort(zpos1, zpos1 + N, CompZPos);
        sort(zpos2, zpos2 + M, CompZPos);
        int idx = 0, mdist = (1 << 30), mdistnum = 0;
        for (int i = 0; i < N; i++) {
            while (idx<M && zpos1[i]>zpos2[idx]) {
                idx++;
            }
            if (idx > 0) {
                int dist = zpos1[i] - zpos2[idx - 1];
                if (dist < mdist) {
                    mdist = dist;
                    mdistnum = 1;
                }
                else if (dist == mdist) {
                    mdistnum++;
                }
            }
            if (idx == M) {
                break;
            }
            int dist = zpos2[idx] - zpos1[i];
            if (dist < mdist) {
                mdist = dist;
                mdistnum = 1;
            }
            else if (dist == mdist) {
                mdistnum++;
            }
        }
        int xdist = c1 > c2 ? c1 - c2 : c2 - c1;
        cout << "#" << tc << " " << xdist + mdist << " " << mdistnum << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool CompZPos(const int& p1, const int& p2) {
    return p1 < p2;
}