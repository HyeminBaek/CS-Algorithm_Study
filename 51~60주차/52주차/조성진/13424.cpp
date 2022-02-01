#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;
int adj[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> N >> M;
        memset(adj, 0x3f, sizeof(adj));
        for(int i = 0; i < M; i++) {
            int a, b, c; cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }
        for(int i = 0; i <= N; i++) {
            adj[i][i] = 0;
        }
        cin >> K;
        vector<int> peoples(K);
        for(int &it: peoples) cin >> it;
        for(int k = 1; k <= N; k++) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int c = 1e9;
        int ret = 1;
        for(int k = 1; k <= N; k++) {
            int tmp = 0;
            for(int people: peoples) {
                tmp += adj[k][people];
            }
            if(c > tmp) {
                c = tmp;
                ret = k;
            }
        }
        cout << ret << "\n";
    }
}