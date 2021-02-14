#include <iostream>
#include <vector>

const int MAX = 10001;
using namespace std;

int n, ans = 0;
vector<int> pre_job[MAX];
int time[MAX];
bool visit[MAX];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int t, m;
        cin >> t >> m;
        time[i] = t;

        while(m--){
            int job; cin >> job;
            pre_job[i].push_back(job);    //선행 작업 저장
        }
    }

    for(int i=1; i<=n; i++){
        int Max = 0;
        for(int j=0; j<pre_job[i].size(); j++){
            Max = max(Max, time[pre_job[i][j]]);
        }
        time[i] += Max;
    }

    for(int i=1; i<=n; i++){
        ans = max(ans, time[i]);
    }

    cout << ans;
}