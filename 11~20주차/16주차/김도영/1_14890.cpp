#include <iostream>

const int MAX = 100;
using namespace std;

int N, L;
int map[MAX][MAX], map2[MAX][MAX];

bool check(int map[][MAX], int y, int x){
    int pivot = map[y][x+1];
    for(int i = x+1; i<x+1+L; i++)
        if(map[y][i] != pivot) return false;

    return true;
}

int solution(int map[][MAX]){
    int cnt = 0;
    for(int i=0; i<N; i++){
        bool flag = true;
        int same = 1;

        for(int j=0; j<N-1; j++){
            if(map[i][j] == map[i][j+1]) 
                same++;
            else if(map[i][j]+1 == map[i][j+1]){    // 오른쪽이 더 높은 경우
                if(L <= same){
                    same = 1;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(map[i][j] == map[i][j+1]+1){
                if(check(map, i, j) == true){
                    same = 0;
                    j = j+L-1;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(abs(map[i][j] - map[i][j+1]) >= 2){
                flag = false;
                break;
            }
        }

        if(flag)
            cnt++;
    }

    return cnt;
}

int main(){
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            map2[j][i] = map[i][j];
        }
    }

    int ans = solution(map);
    ans += solution(map2);

    cout << ans;
}