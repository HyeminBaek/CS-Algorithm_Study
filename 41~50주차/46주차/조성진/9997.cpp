#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int all = (1 << 26) - 1;
vector<int> v;

int str2int(string str) {
    int ret = 0;
    for(auto c: str) {
        ret |= (1 << (c - 'a'));
    }
    return ret;
}

int solve(int pos, int num) {
    if(pos == n) {
        if(num == all) return 1;
        return 0;
    }
    int ret = solve(pos+1, num) + solve(pos+1, num | v[pos]);
    return ret;
}

int main() {
    cin >> n; 
    v.resize(n);
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        v[i] = str2int(str);
    }
    int ret = solve(0, 0);
    cout << ret << "\n";
}
