#include <iostream>
#include <vector>
#include <cstdlib>

const int MAX = 21;
using namespace std;

int n, answer = 987654321;
int map[MAX][MAX];
vector<int> start, link;

int Calculation(){
    int s = 0, l = 0;

    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i==j) continue;

            s += map[start[i]][start[j]];
            l += map[link[i]][link[j]];
        }
    }

    return abs(s-l);
}

void Backtrack(int cnt){
    if(cnt == n+1){
        if(start.size() == n/2 && link.size() == n/2){
            answer = min(answer, Calculation());
        }
        return;
    }

    start.push_back(cnt);
    Backtrack(cnt+1);
    start.pop_back();

    link.push_back(cnt);
    Backtrack(cnt+1);
    link.pop_back();
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    Backtrack(1);
    cout << answer;
}