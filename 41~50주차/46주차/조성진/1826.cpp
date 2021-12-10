#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
int L, P;
vector<pii> v;

int main() {
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        int d, o; cin >> d >> o;
        v[i] = pii(d, o);
    }
    sort(v.begin(), v.end());
    cin >> L >> P;
    priority_queue<int> q;
    q.push(P);
    int ret = -1;
    int idx = 0;
    int pos = 0;
    while(!q.empty()) {
        int oil = q.top(); q.pop();
        pos += oil;
        ret += 1;
        if(pos >= L) {
            cout << ret << "\n";
            return 0;
        }
        while(v[idx].first <= pos && idx < n) {
            q.push(v[idx].second);
            idx += 1;
        }
    }
    cout << -1 << "\n";
    return 0;
}
