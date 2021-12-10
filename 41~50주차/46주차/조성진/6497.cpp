#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;

int m, n;

struct DisjointSet {
    int n;
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
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
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    m = -1, n = -1;
    while(1) {
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        int ret = 0;
        priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
        DisjointSet ds(m);
        for(int i = 0; i < n; i++) {
            int p1, p2, dis; cin >> p1 >> p2 >> dis;
            pq.push(tiii(dis, p1, p2));
        }
        while(!pq.empty()) {
            tiii now = pq.top(); pq.pop();
            int cost = get<0>(now), p1 = get<1>(now), p2 = get<2>(now);
            if(ds.find(p1) == ds.find(p2)) ret += cost;
            else {
                ds.merge(p1, p2);
            }
        }
        cout << ret << "\n";
    }

}
