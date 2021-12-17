#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dx[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0 ,0 ,0, -1, -1, -1};

int R, C;
vector<string> board;
string action;

int abs(int x) {
    return x > 0 ? x : -x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string str; cin >> str;
        board.push_back(str);
    }
    pii jong_loc = pii(-1, -1);
    queue<pii> q;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'I') {
                jong_loc = pii(i, j);
            } else if(board[i][j] == 'R') {
                q.push(pii(i, j));
            }
        }
    }
    cin >> action;
    bool dead = false;
    int turn = 0;
    for(auto c: action) {
        int d = c - '0';
        int is_visit[101][101];
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                is_visit[i][j] = 0;
            }
        }
        turn += 1;
        // 종수의 이동
        jong_loc = pii(jong_loc.first + dy[d], jong_loc.second + dx[d]);
        int j_y =  jong_loc.first, j_x = jong_loc.second;
        int dY = 0, dX = 0;
        while(!q.empty()) {
            pii now = q.front(); q.pop();
            int r_y = now.first, r_x = now.second;
            // 종수가 미친 아두이노가 있는 칸으로 이동하면 게임이 끝남
            if(r_y == j_y && r_x == j_x) {
                dead = true;
                break;
            }
            // 미친 아두이노가 종수와 가장 가까운 방향으로 한칸 이동
            dY = (r_y == j_y) ? 0 : -(r_y - j_y) / abs(r_y - j_y);
            dX = (r_x == j_x) ? 0 : -(r_x - j_x) / abs(r_x - j_x);
            int next_y = r_y + dY, next_x = r_x + dX;
            // 미친 아두이노가 종수와 만나면 게임이 끝남
            if(next_y == j_y && next_x == j_x) {
                dead = true;
                break;
            }
            // 아무경우도 아닌경우 방문체크
            is_visit[next_y][next_x]++;
        }
        if(dead) break;

        // 2번이상 방문됬으면 미친 아두이노가 터지므로 1번만 방문한 곳만 골라서 다시 큐에 넣음
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(is_visit[i][j] == 1) q.push(pii(i, j));
            }
        }
    }
    // 죽었을때의 출력
    if(dead) {
        cout << "kraj " << turn << "\n";
        return 0;
    } else {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                board[i][j] = '.';
            }
        }
        board[jong_loc.first][jong_loc.second] = 'I';
        while(!q.empty()) {
            int r_y = q.front().first, r_x = q.front().second; q.pop();
            board[r_y][r_x] = 'R';
        }

        for(int i = 0; i < R; i++) {
            cout << board[i] << "\n";
        }

    }
}
