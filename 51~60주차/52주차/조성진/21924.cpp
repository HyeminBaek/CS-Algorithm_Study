#include <bits/stdc++.h>

using namespace std;

struct Street {
    int cost;
    int A;
    int B;
};

struct DS {
    vector<int> parent, rank;
    DS(int n):parent(n+1), rank(n+1,1) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        u = find(u); v = find(v);
        if(u==v) return 0;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
        return 1;
    }
};

struct compare {
    bool operator()(Street& s1, Street& s2) {
        if(s1.cost == s2.cost) {
            return s1.A < s2.A;
        }
        return s1.cost > s2.cost;

    }
};

int main() {
    int N, M; cin >> N >> M;
    DS t(N);
    priority_queue<Street, vector<Street>, compare > pq;
    for(int i = 0; i < M; i++) {
        int n1, n2, cost; cin >> n1 >> n2 >> cost;
        pq.push({cost, n1, n2});
    }
    long long ret = 0;
    int cnt = 0;
    while(!pq.empty()) {
        Street now = pq.top(); pq.pop();
        if(t.merge(now.A, now.B)) {
            cnt += 1;
            continue;
        }
        ret += now.cost;
    }
    cout << (cnt == N-1 ? ret : -1) << "\n";

}