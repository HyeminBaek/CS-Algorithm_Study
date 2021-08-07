#include<iostream>
#include<utility>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int T, N;
string s[300];
bool iszero[300][300], visit[300][300];
pii dir[8] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
void init();
int BFS();
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }

        init();
        cout << "#" << tc << " " << BFS() << "\n";
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] == '.') {
                visit[i][j] = false;
                iszero[i][j] = true;
                for (int d = 0; d < 8; d++) {
                    int nr = i + dir[d].first;
                    int nc = j + dir[d].second;
                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    if (s[nr][nc] == '*') {
                        iszero[i][j] = false;
                        break;
                    }
                }
            }
            else {
                visit[i][j] = true;//지뢰칸일 경우
            }
        }
    }
}
int BFS() {
    int ret = 0;
    queue<pii> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j] && iszero[i][j]) {
                ret++;
                visit[i][j] = true;
                q.push({ i,j });
                while (!q.empty()) {
                    pii t = q.front();
                    q.pop();
                    for (int d = 0; d < 8; d++) {
                        int nr = t.first + dir[d].first;
                        int nc = t.second + dir[d].second;
                        if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;
                        visit[nr][nc] = true;
                        if (iszero[nr][nc]) {
                            q.push({ nr,nc });
                        }
                    }

                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!iszero[i][j] && !visit[i][j]) {
                ret++;
            }
        }
    }
    return ret;
}