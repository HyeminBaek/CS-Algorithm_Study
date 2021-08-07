#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;
typedef pair<int, int> pii;
int T, N, K, a, b, c;
pii sum[100];
string answer;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            sum[i].first = 0;
            sum[i].second = i;
            cin >> a >> b >> c;
            sum[i].first += a * 7;
            sum[i].first += b * 9;
            sum[i].first += c * 4;
        }
        sort(sum, sum + N);
        for (int i = 0; i < N; i++) {

            if (sum[i].second + 1 == K) {
                int r = (i * 10) / N;

                if (r == 0) {
                    answer = "D0";
                }
                else if (r <= 3) {
                    answer = "C";
                }
                else if (r <= 6) {
                    answer = "B";
                }
                else {
                    answer = "A";
                }
                if (r != 0) {
                    int m = r % 3;
                    if (m == 1) {
                        answer += '-';
                    }
                    else if (m == 2) {
                        answer += '0';
                    }
                    else {
                        answer += '+';
                    }
                }
                cout << "#" << tc << " " << answer << "\n";
                break;
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}