#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
vector<vector<int> > g;
string colors;
vector<bool> visit;

struct uf {
    vector<int> rank, parent, value; 
    uf(int size): rank(size, 1), parent(size), value(size, 1) {
        for(int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u]) return u;
        else return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        value[v] += value[u];
        if(rank[u] == rank[v]) rank[v]++;
    }
};

void search(struct uf& ds, int src) {
    for(int next: g[src]) {
        if(colors[next] == 'B') continue;
        if(visit[next] == true) continue;
        visit[next] = 1;
        ds.merge(src, next);
        search(ds, next);
    }
    return ;
}

ll solve(struct uf& ds, int src) {
    ll ret = 0;
    for(int next: g[src]) {
        if(colors[next] == 'B') continue;
        ret += (ll)ds.value[ds.find(next)];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    g.assign(n, vector<int>());
    struct uf ds(n);
    visit.assign(n, 0);
    for(int i = 0; i < n-1; i++) {
        int p,q; cin >> p >> q;
        p -= 1; q -= 1;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    cin >> colors;
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        if(colors[i] == 'R' && !visit[i]) {
            search(ds, i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(colors[i] == 'B') {
            ret += solve(ds, i);
        }
    }
    cout << ret << "\n";
}
