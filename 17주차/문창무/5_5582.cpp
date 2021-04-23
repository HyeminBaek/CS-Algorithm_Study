#include <algorithm>
#include <iostream>
using namespace std;

string s1, s2;
int lcs[4001][4001];

// 두 문자열의 LCS(longest common subsequence) dp 문제
// 케이스1: s1[i] == s2[j]일 때, 전체의 lcs는 이전까지 구한 lcs+(이번에 검사한 문자)
// 케이스2: s1[i] != s2[j]일 때, 그 다음 인덱스부터 다시 lcs구하기 시작

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, s1);
    getline(cin, s2);

    int ans = 0;
    for (int i = 1; i <= s1.length(); ++i) {
        for (int j = 1; j <= s2.length(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                ans = max(ans, lcs[i][j]);
            }
        }
    }

    cout << ans;
    return 0;
}
