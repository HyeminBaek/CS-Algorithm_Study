#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct P {
    int to, w;
};

int n, m, s, e;
vector<P> g[100001];

bool isPossible(int mid) {
    queue<int> q;
    q.push(s);

    vector<bool> visited(n + 1, 0);
    visited[s] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &p : g[cur]) {
            int next = p.to;
            int w = p.w;
            if (!visited[next] && mid <= w) {
                if (next == e) return true;
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m >> s >> e;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back((P){b, c});
        g[b].push_back((P){a, c});
    }

    int S = 1, E = 1000000;
    while (S <= E) {
        int mid = (S + E) / 2;
        if (isPossible(mid))
            S = mid + 1;
        else
            E = mid - 1;
    }
    cout << S - 1;
    return 0;
}