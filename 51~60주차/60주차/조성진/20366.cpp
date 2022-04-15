#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    int ret = INT_MAX;
    for(int lo = 0; lo < N; lo++) {
        for(int hi = N-1; hi-lo > 2; hi--) {
            int l = lo+1, r = hi-1;
            int lsum = V[lo] + V[hi];
            while(l < r) {
                int rsum = V[l] + V[r];
                int diff = lsum - rsum;
                if(ret > abs(diff)) {
                    ret = abs(diff);
                }
                if(diff > 0) {
                    l++;
                } else if(diff < 0) {
                    r--;
                } else {
                    cout << 0 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << ret << "\n";
}