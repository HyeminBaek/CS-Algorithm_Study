#include <bits/stdc++.h>
#define BIG_NUMBER 1000
using namespace std;
int N, M;
vector<vector<int> > V(101*BIG_NUMBER + 101);
int board[101][101];
int visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inRange(int x, int y) {
    return 1 <= x and x <= N and 1 <= y and y <= N;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        V[x1*BIG_NUMBER+y1].push_back(x2*BIG_NUMBER+y2);
    }
    int ret = 1;
    board[1][1] = 1;
    queue<int> q;
    q.push(1001);
    while(!q.empty()) {
        int qnum = q.front(); q.pop();
        int qx = qnum / BIG_NUMBER; 
        int qy = qnum % BIG_NUMBER;
        if(visited[qx][qy]) continue;
        visited[qx][qy] = 1;
        for(int u = 0 ; u < 4; u++) {
            int qnx = qx + dx[u], qny = qy + dy[u];
            if(inRange(qnx, qny)) {
                if(!visited[qnx][qny] && board[qnx][qny]) {
                    q.push(qnx*BIG_NUMBER+qny);
                }
            }

        }
        for(auto num: V[qnum]) {
            int x = num / BIG_NUMBER; 
            int y = num % BIG_NUMBER;
            if(board[x][y] == 0) {
                ret++;
                board[x][y] = 1;
            }
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(inRange(nx, ny)) {
                    if(visited[nx][ny]) {
                        q.push(num);
                    }
                }
            }
        }
    }
    cout << ret << "\n";
}