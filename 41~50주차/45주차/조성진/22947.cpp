#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k;
vector<int> times;
vector<vector<int> > g;

int ret = 1e9;
int dst = 0;

int solve(int src, vector<int>& times, vector<int> ins) {
    queue<int> q;
    vector<int> dist(n, 0);
    dist[src] = times[src];
    q.push(src); 
    int ret = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(auto next: g[now]) {
            ins[next]--;
            dist[next] = max(dist[next], dist[now] + times[next]);
            ret = max(ret, dist[next]);
            if(ins[next] == 0) {
                q.push(next);
            }
        }
    }
    return ret;
}

void makeZero(vector<int>& times, int pos, int zeroed, vector<int>& ins) {
    if(pos == n) {
        if(zeroed == k) ret = min(ret, solve(0, times, ins));
        return;
    }
    int save = times[pos];
    if(zeroed < k && pos != dst) {
        times[pos] = 0;
        makeZero(times, pos+1, zeroed+1, ins);
        times[pos] = save;
    }
    makeZero(times, pos+1, zeroed, ins);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    times.assign(n, 0);
    for(auto &x: times) cin >> x;
    g.assign(n, vector<int>());
    vector<int> ins(n, 0);
    vector<int> outs(n, 0);
    for(int i = 0; i < m; i++) {
        int s,d; cin >> s >> d;
        g[s-1].push_back(d-1);
        ins[d-1]++;
        outs[s-1]++;
    }
    for(int i = 0; i < n; i++) {
        if(outs[i] == 0) {
            dst = i;
            break;
        }
    }

    makeZero(times, 1, 0, ins);
    cout << ret << "\n";

}