#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int profits[302][302];
int pSum[302][302];

void pre() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pSum[i][j] = profits[i][j] + pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1];
        }
    }
}

int getProfit(int y, int x) {
    int k = 0;
    int ret = -1e9;
    while(1) {
        if(y+k > n || x+k > n) break;
        ret = max(ret, pSum[y+k][x+k] - pSum[y-1][x+k] - pSum[y+k][x-1] + pSum[y-1][x-1]);
        k += 1;
    }
    return ret;
}

int solve() {
    int ret = -1e9;;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ret = max(ret, getProfit(i, j));
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> profits[i][j];
    }

    pre();
    
    int ret = solve();
    cout << ret << "\n";
    return 0;
}