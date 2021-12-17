#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<string> states;
int costs[1001][1001];
int dist[1001];

int calculate(int i, int j) {
    string s1 = states[i], s2 = states[j];
    int ret = 0;
    int len = s1.length();
    for(int k = 0; k < len; k++) {
        int tmp = s1[k] - s2[k];
        ret += tmp*tmp;
    }
    return ret;
}

void pre() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            costs[i][j] = calculate(i, j);
        }
    }
}

int main() {
    cin >> n;
    fill(dist, dist+1001, 1e9);
    states.resize(n);
    for(auto &it: states) cin >> it;

    pre();

    int src, dst; cin >> src >> dst;
    src -= 1; dst -= 1;
    dist[src] = 0;
    int distMin = 1e9;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, src));
    while(!pq.empty()) {
        pii now = pq.top(); pq.pop();
        int nowCost = now.first, nowPos = now.second;
        if(nowCost > dist[nowPos]) continue;
        for(int nextPos = 0; nextPos < n; nextPos++) {
            int nextCost = nowCost + costs[nowPos][nextPos];
            if(dist[nextPos] > nextCost) {
                dist[nextPos] = nextCost;
                pq.push(pii(nextCost, nextPos));
            }
        }
    }
    cout << dist[dst] << "\n";
    return 0;
}