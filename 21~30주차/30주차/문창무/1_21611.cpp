#include <cstring>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, -1, 1, 0, 0};
const int dc[] = {0, 0, 0, -1, 1};

int n, m, center, b1, b2, b3;
vector<pii> order;
int board[51][51];
int nBoard[51][51];

void makeOrder() {
    const int ndr[] = {0, 0, 1, 0, -1};  // 좌하우상
    const int ndc[] = {0, -1, 0, 1, 0};
    int r = center, c = center;
    order.push_back({r, c});  // 상어 (4,4)

    int len = 1;
    while (1) {  // 왼1 아래1 오른12 위12 왼123 아래123 ...
        if (order.size() >= n * n) break;
        for (int d = 1; d <= 4; ++d) {
            for (int i = 1; i <= len; ++i) {
                r += ndr[d];
                c += ndc[d];
                if (1 > r || 1 > c || n < r || n < c) return;

                order.push_back({r, c});
            }
            if (d % 2 == 0) ++len;
        }
    }
}

void blizzard() {
    int d, s;
    cin >> d >> s;
    int r = center, c = center;

    for (int i = 1; i <= s; ++i) {
        r += dr[d];
        c += dc[d];
        if (1 > r || 1 > c || r > n || c > n) break;

        board[r][c] = 0;
    }
}

void rearrange() {
    vector<int> marble = {0};  // 상어
    for (int i = 1; i < order.size(); ++i) {
        int r = order[i].first;
        int c = order[i].second;
        if (board[r][c] != 0) {
            marble.push_back(board[r][c]);
        }
    }

    memset(board, 0, sizeof(board));
    for (int i = 0; i < marble.size(); ++i) {
        int r = order[i].first;
        int c = order[i].second;
        board[r][c] = marble[i];
    }
}

bool explosion() {
    int target = board[center][center - 1];  // 탐색 시작점
    vector<pii> seq = {{center, center - 1}};
    bool flag = false;

    for (int i = 2; i < order.size(); ++i) {
        int r = order[i].first;
        int c = order[i].second;

        if (target == board[r][c]) {
            seq.push_back({r, c});
        } else {
            if (seq.size() >= 4) {
                flag = true;
                if (target == 1)
                    b1 += seq.size();
                else if (target == 2)
                    b2 += seq.size();
                else if (target == 3)
                    b3 += seq.size();

                for (pii& p : seq) {
                    board[p.first][p.second] = 0;
                }
            }
            target = board[r][c];
            seq.clear();
            seq.push_back({r, c});
        }
    }

    if (flag) return true;
    return false;
}

void change() {  // A: 갯수, B: 구슬번호
    memset(nBoard, 0, sizeof(nBoard));

    int target = board[center][center - 1];
    vector<pii> seq = {{center, center - 1}};
    int nStart = 1;

    for (int i = 2; i < order.size(); ++i) {
        int r = order[i].first;
        int c = order[i].second;

        if (target == board[r][c]) {
            seq.push_back({r, c});
        } else {
            pii& apos = order[nStart];      // 갯수
            pii& bpos = order[nStart + 1];  // 구슬번호
            nStart += 2;
            nBoard[apos.first][apos.second] = seq.size();
            nBoard[bpos.first][bpos.second] = target;

            target = board[r][c];
            seq.clear();
            seq.push_back({r, c});
        }
        if (nStart >= order.size()) break;
    }

    memcpy(board, nBoard, sizeof(board));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    center = (n + 1) / 2;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }

    makeOrder();
    while (m--) {
        blizzard();
        rearrange();
        while (1) {
            bool flag = explosion();
            if (!flag) break;
            rearrange();
        }
        change();
    }

    cout << b1 + 2 * b2 + 3 * b3;
    return 0;
}
