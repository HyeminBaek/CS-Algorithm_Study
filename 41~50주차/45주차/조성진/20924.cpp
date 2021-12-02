#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, r;
int g;
vector<vector<pii> > tree;
vector<int> is_visit;

int r2g(int root) {
    int ret = 0;
    is_visit[root] = 1;

    queue<int> q;
    q.push(root);
    int backNumber = 0;
    int backDist = 0;
    int done_flag = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        int neighbor_cnt = 0;
        for(auto next: tree[now]) {
            if(!is_visit[next.first]) {
                neighbor_cnt++;
                if(neighbor_cnt > 1) {
                    is_visit[backNumber] = 0;
                    ret -= backDist;
                    done_flag = 1;
                    break;
                }
                backNumber = next.first;
                backDist = next.second;
                is_visit[next.first] = 1;
                ret += next.second;
                g = now;
                q.push(backNumber);
            }
        }
        if(done_flag) break;
        if(neighbor_cnt == 0) break;
    }
    return ret;
}

int g2l(int now) {
    int ret = 0;
    for(auto next: tree[now]) {
        int nextNode = next.first, nextDist = next.second;
        if(is_visit[nextNode]) continue;
        is_visit[nextNode] = 1;
        ret = max(ret, nextDist + g2l(nextNode));
    }
    return ret;
}
int main() {
    scanf("%d %d", &n, &r);
    tree.assign(n+1, vector<pii>());
    is_visit.assign(n+1, 0);

    for(int i = 0; i < n-1; i++) {
        int p1, p2, dist; scanf("%d %d %d", &p1, &p2, &dist);
        tree[p1].push_back(pii(p2, dist));
        tree[p2].push_back(pii(p1, dist));
    }

    int root_to_giga = r2g(r);
    int giga_to_leaf = g2l(g);
    printf("%d %d\n", root_to_giga, giga_to_leaf);
}