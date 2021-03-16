#include <iostream>
#include <queue>

const int MAX = 20;
using namespace std;

int n, ans = 0;
int map[MAX][MAX];
pair<int, int> movdir[] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

void Copy(int a[MAX][MAX], int t[MAX][MAX]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            t[i][j] = a[i][j];
        }
    }
}

int get_max(){
    int temp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0) continue;
            temp = max(temp, map[i][j]);
        }
    }

    return temp;
}

void Move_map(int dir){
    queue<int> q;

    //오른쪽
    if(dir == 0){
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;            
            }

            int idx = n-1;
            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[i][idx] == 0){
                    map[i][idx] = data;
                }
                else if(map[i][idx] == data){
                    map[i][idx--] *= 2;
                }
                else{
                    map[i][--idx] = data;
                }
            }
        }
    }
    //왼쪽
    else if(dir == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }

            int idx = 0;
            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[i][idx] == 0){
                    map[i][idx] = data;
                }
                else if(map[i][idx] == data){
                    map[i][idx++] *= 2;
                }
                else{
                    map[i][++idx] = data;
                }
            }
        }
    }
    //아래
    else if(dir == 2){
        for(int j=0; j<n; j++){
            for(int i=n-1; i>=0; i--){
                if(map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }

            int idx = n-1;
            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[idx][j] == 0){
                    map[idx][j] = data;
                }
                else if(map[idx][j] == data){
                    map[idx--][j] *= 2;
                }
                else{
                    map[--idx][j] = data;
                }
            }
        }
    }
    //위
    else if(dir == 3){
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                if(map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }

            int idx = 0;
            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[idx][j] == 0){
                    map[idx][j] = data;
                }
                else if(map[idx][j] == data){
                    map[idx++][j] *= 2;
                }
                else{
                    map[++idx][j] = data;
                }
            }
        }
    }
}

void Backtrak(int cnt){
    if(cnt == 5){
        ans = max(ans, get_max());
        return;
    }

    //원래 값들 지키기
    int t_map[MAX][MAX];
    Copy(map, t_map);

    for(int i=0; i<4; i++){
        Move_map(i);
        Backtrak(cnt+1);
        
        //되돌리기
        Copy(t_map, map);
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    Backtrak(0);
    cout << ans;
}