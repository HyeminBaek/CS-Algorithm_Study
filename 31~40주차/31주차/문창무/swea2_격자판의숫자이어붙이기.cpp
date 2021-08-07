#include <iostream>
#include <unordered_set>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int tc;
char board[4][4];
unordered_set<string> uset;

void dfs(int r, int c, string s) {
    if (s.length() == 7) {
        uset.insert(s);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || 4 <= nr || 4 <= nc) continue;

        dfs(nr, nc, s + board[nr][nc]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        uset.clear();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                dfs(i, j, "");
            }
        }

        cout << '#' << t << ' ' << uset.size() << '\n';
    }

    return 0;
}
