#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;

int n, k, m;
vector<vector<int> > g;
vector<vector<int> > connectedTube;
vector<int> dist;
vector<int> visitedTube;


int solve(int src) {
    dist.assign(n+1, 1e9);
    visitedTube.assign(m+1, 0);
    dist[src] = 1;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(pii(1, src));
    int ret = -1;
    while(!q.empty()) {
        pii nowState = q.top();
        q.pop();
        int nowDist = nowState.first, nowPos = nowState.second;
        if(nowPos == n) return nowDist;
        if(dist[nowPos] < nowDist) continue;
        for(auto tubeNumber: connectedTube[nowPos]) {
            if(visitedTube[tubeNumber]) continue;
            visitedTube[tubeNumber] = 1;
            for(auto next: g[tubeNumber]) {
                if(dist[next] < nowDist+1) continue;
                dist[next] = nowDist + 1;
                q.push(pii(nowDist+1, next));
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    g.assign(m+1, vector<int>());
    connectedTube.assign(n+1, vector<int>());
    for(int i = 1; i <= m; i++) {
        vector<int> tmp(k, 0);
        for(auto &x: tmp) {
            cin >> x;
            connectedTube[x].push_back(i);
        }
        g[i] = tmp;
    }
    int ret = solve(1);
    cout << ret << "\n";
}
