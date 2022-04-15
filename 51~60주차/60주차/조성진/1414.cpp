#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
int N;
vector<tiii> adj;

struct UF {
    vector<int> parent, rank;
    UF(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return 0;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; adj.resize(N);
    int ret = 0;
    UF uf(N);
    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        for(int j = 0; j < N; j++) {
            char c = str[j];
            if(c == '0') continue;
            if(c >= 'a') {
                ret += (c-'a'+1);
                adj.push_back(tiii(c-'a'+1, i, j));
            } else {
                ret += (c-'A'+27);
                adj.push_back(tiii(c-'A'+27, i, j));
            }
        }
    }

    sort(adj.begin(), adj.end());
    int cnt = 0;
    for(int k = 0; k < adj.size(); k++) {
        auto [dist, n1, n2] = adj[k];
        if(uf.merge(n1, n2)) {
            ret -= dist;
            cnt++;
        }
    }
    if(cnt != N-1) ret = -1;
    cout << ret << "\n";
}