#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> pos;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; 
    v.assign(n, 0); pos.assign(n, 0);
    int idx = 0;
    for(auto &x: v) {
        cin >> x; x--;
        pos[x] = idx++;
    }
    int acc = 1;
    int max_acc = 0;
    for(int i = 0; i < n-1; i++) {
        if(pos[i] < pos[i+1]) {
            acc++;
        } else {
            max_acc = max(max_acc, acc);
            acc = 1;
        }
    }
    max_acc = max(max_acc, acc);
    cout << n-max_acc << "\n";
}