#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <deque>

const int N = 4, M = 8;
using namespace std;

int K, idx, d;
int cycle[4];
vector<int> v[4];

void left(int idx){
    if(idx < 0){
        return;
    }

    if(v[idx][2] != v[idx+1][6]){
        cycle[idx] = cycle[idx+1] * -1;
        left(idx-1);
    }
    
    return;
}

void right(int idx){
    if(N <= idx){
        return;
    }

    if(v[idx][6] != v[idx-1][2]){
        cycle[idx] = cycle[idx-1]*-1;
        right(idx+1);
    }

    return;
}

int main(){
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<M; j++){
            v[i].push_back(s[j]-'0');
        }
    }

    cin >> K;
    for(int i=0; i<K; i++){
        memset(cycle, 0, sizeof(cycle));
        cin >> idx >> d;
        idx -= 1;
        cycle[idx] = d;

        // 회전 방향 정하기
        if(0 < idx)
            left(idx-1);
        if(idx < 3)
            right(idx+1);


        // 톱니들 회전 시켜주기
        for(int i=0; i<N; i++){
            if(cycle[i] == 0) continue;

            deque<int> dq;
            for(int j=0; j<M; j++)
                dq.push_back(v[i][j]);

            if(cycle[i] == 1){    // 시계방향
                dq.push_front(dq.back());
                dq.pop_back();    
            }
            else if(cycle[i] == -1){    //반시계
                dq.push_back(dq.front());
                dq.pop_front();
            }

            v[i].clear();
            for(int j=0; j<M; j++){
                v[i].push_back(dq.front());
                dq.pop_front();
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        if(v[i][0] == 1){
            ans += pow(2, i);
        }
    }

    cout << ans;
}