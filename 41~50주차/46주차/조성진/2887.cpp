#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
int n;
vector<pii> Xs;
vector<pii> Ys;
vector<pii> Zs;

struct DS {
    int n;
    vector<int> parent, rank;
    DS(int n): parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    struct DS ds(n);
    for(int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        Xs.push_back(pii(x, i));
        Ys.push_back(pii(y, i));
        Zs.push_back(pii(z, i));
    }
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    sort(Zs.begin(), Zs.end());
    for(int i = 0; i < n-1; i++) {
        pq.push(tiii(Xs[i+1].first-Xs[i].first, Xs[i].second, Xs[i+1].second));
        pq.push(tiii(Ys[i+1].first-Ys[i].first, Ys[i].second, Ys[i+1].second));
        pq.push(tiii(Zs[i+1].first-Zs[i].first, Zs[i].second, Zs[i+1].second));
    }
    int connect = 0;
    int ret = 0;
    while(connect < n-1) {
        tiii now = pq.top(); pq.pop();
        int cost = get<0>(now), p1 = get<1>(now), p2 = get<2>(now);
        if(ds.find(p1) == ds.find(p2)) continue;
        connect += 1;
        ds.merge(p1, p2);
        ret += cost;
    }
    cout << ret << "\n";

}
