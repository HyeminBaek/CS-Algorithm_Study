#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n, m;
ll cache[2001][11];

ll dfs(int now, int depth) {
    if(now > m) return 0;
    if(depth == n) return 1;
    ll& ret = cache[now][depth];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = now*2; i * (1 << (n-depth-1)) <= m; i++) {
        ret += dfs(i, depth+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        ll ret = 0;
        for(int i = 1; i * (1 << (n-1)) <= m; i++) {
            ret += dfs(i, 1);
        }
        cout << ret << "\n";
    }
}
