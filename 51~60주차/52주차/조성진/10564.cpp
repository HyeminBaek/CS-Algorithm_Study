#include <bits/stdc++.h>
using namespace std;
int N, M;
int cache[5001][5001];
int solve(vector<int>& scores, int prev_action, int prev_score) {
    if(prev_action > N) return 0;
    int& ret = cache[prev_action][prev_score];
    if(ret != -1) return ret;
    ret = 1;
    for(int score: scores) {
        solve(scores, prev_action + prev_score + score, prev_score + score);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TT; cin >> TT;
    while(TT--) {
        memset(cache, -1, sizeof(cache));
        cin >> N >> M;
        vector<int> scores(M);
        int ret = -1;
        for(auto &it: scores) {
            cin >> it;
        }
        solve(scores, 0, 0);
        for(int j = 1; j <= N; j++) {
            if(cache[N][j] == 1) ret = j;
        }
        cout << ret << "\n";
    }
}