#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

const int MAX = pow(2, 6);
using namespace std;

int n, q, l;
int map[MAX][MAX];
int temp[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> movdir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Copy(int a[MAX][MAX], int b[MAX][MAX]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = b[i][j];
        }
    }
}

void Cycle(int y, int x, int p){
    int row = y, col = x;
    for(int j=x+p-1; j>=x; j--){
        for(int i=y; i<y+p; i++){
            temp[i][j] = map[row][col];
            col += 1;
        }
        row += 1;
        col = x;
    }
}

void Melt(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0) continue;

            int cnt = 0;
            for(int d= 0; d<4; d++){
                int ny = i + movdir[d].first;
                int nx = j + movdir[d].second;

                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(map[ny][nx] > 0){
                        cnt++;
                    }
                }    
            }

            if(cnt < 3){
                temp[i][j]--;
            }
        }
    }
    Copy(map, temp);
}

int BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visit[a][b] = true;

    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;
            
            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                if(map[ny][nx] > 0 && visit[ny][nx] == false){
                    visit[ny][nx] = true;
                    q.push({ny, nx});
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main(){
    int e;
    cin >> e >> q;
    n = pow(2, e);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    /*
        백준 문제 그림 형식
        마법 시전하기 전 -> L=1
        마법 시전하기 전 -> L=2    
    */
    while(q--){
        cin >> l;
        memset(temp, 0, sizeof(temp));


        int pivot = pow(2, l);
        for(int i=0; i<n; i+=pivot){
            for(int j=0; j<n; j+=pivot){
                Cycle(i, j, pivot);
            }
        }
        if(l != 0){
            Copy(map, temp);
        }
        
        //all_print();
        Melt();
        //all_print();
    }

    int ans = 0, lump = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += map[i][j];
            
            if(map[i][j] > 0 && visit[i][j] == false){
                lump = max(lump, BFS(i, j));
            }
        }
    }

    cout << ans << "\n" << lump;
    return 0;
}