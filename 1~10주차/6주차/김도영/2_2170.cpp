#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 1e9;
using namespace std;

vector<pair<int, int>> v;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int start = -INF, end = -INF;
    for(int i=0; i<v.size(); i++){
        int x1 = v[i].first;
        int x2 = v[i].second;

        if(start <= x1 && x2 <= end)
            continue;

        //선분에 더해주기
        ans += (x2 - x1);
        if(x1 < end){
            //겹치는 부분 빼주기
            ans -= (end - x1);
        }

        start = x1;
        end = x2;
    }

    cout << ans;
}