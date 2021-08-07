// boj 14890 경사로
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
int N, L;  // 100, 경사로길이100
vector<vector<int>> v(MAX, vector<int>(MAX));
vector<int> line(MAX);

// row, column에 대한 1차원 배열을 받아와서 검사
bool isPossible(vector<int>& line) {
    vector<bool> c(MAX);
    for (int i = 1; i < N; ++i) {
        if (line[i - 1] != line[i]) {                          // 높이 차이가 나는 경우
            if (abs(line[i] - line[i - 1]) > 1) return false;  // 1이상 차이나면 안됨

            if (line[i - 1] < line[i]) {  // 오르막
                for (int j = 1; j <= L; ++j) {
                    if (i - j < 0) return false;                   // 왼쪽으로 넘어가면 안됨
                    if (line[i - 1] != line[i - j]) return false;  // 경사로 지점간 높이 차이 있으면 안됨
                    if (c[i - j]) return false;                    // 경사로가 이미 놓여있으면 안됨
                    c[i - j] = true;
                }
            } else {  // 내리막
                for (int j = 0; j < L; ++j) {
                    if (i + j >= N) return false;
                    if (line[i] != line[i + j]) return false;
                    if (c[i + j]) return false;
                    c[i + j] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            line[j] = v[i][j];
        }

        if (isPossible(line)) ans++;
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            line[i] = v[i][j];
        }
        if (isPossible(line)) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
