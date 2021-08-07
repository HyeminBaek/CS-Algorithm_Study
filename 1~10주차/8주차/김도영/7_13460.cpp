#include <iostream>
#include <cmath>

using namespace std;

typedef struct _INFO{
    int y;
    int x;
}INFO;

int n, m, Min = 999;
string map[10][10];
INFO Red, Blue;
pair<int, int> movdir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Reverse(int dir){
    if(dir == 0) return 1;
    else if(dir == 1) return 0;
    else if(dir == 2) return 3;
    return 2;
}

int cal(INFO obj, INFO new_obj){
    return abs(new_obj.y - obj.y) + abs(new_obj.x - obj.x);
}

void DFS(INFO Red, INFO Blue, int dir, int cnt){
    if(cnt >= Min) return;
    if(cnt > 10) return;

    INFO next_Red, next_Blue;
    bool flag_Red = false, flag_Blue = false;

    next_Red = {Red.y + movdir[dir].first, Red.x + movdir[dir].second};
    while(1){
        if(map[next_Red.y][next_Red.x] == "#") break;
        if(map[next_Red.y][next_Red.x] == "O"){
            flag_Red = true;
            break;
        }
        next_Red = {next_Red.y + movdir[dir].first, next_Red.x + movdir[dir].second};
    }
    next_Red = {next_Red.y - movdir[dir].first, next_Red.x - movdir[dir].second};

    next_Blue = {Blue.y + movdir[dir].first, Blue.x + movdir[dir].second};
    while(1){
        if(map[next_Blue.y][next_Blue.x] == "#") break;
        if(map[next_Blue.y][next_Blue.x] == "O"){
            flag_Blue = true;
            break;
        }
        next_Blue = {next_Blue.y + movdir[dir].first, next_Blue.x + movdir[dir].second};
    }
    next_Blue = {next_Blue.y - movdir[dir].first, next_Blue.x - movdir[dir].second};

    if(flag_Blue){
        return;
    }
    else if(flag_Red){
        Min = min(Min, cnt);
        return;
    }
    
    if(next_Red.y == next_Blue.y && next_Red.x == next_Blue.x){
        int dist_Red = cal(Red, next_Red);
        int dist_Blue = cal(Blue, next_Blue);
        if(dist_Red < dist_Blue){
            next_Blue = {next_Blue.y - movdir[dir].first, next_Blue.x - movdir[dir].second};
        }
        else{
            next_Red = {next_Red.y-movdir[dir].first, next_Red.x - movdir[dir].second};
        }
    }

    for(int i=0; i<4; i++){
        if(dir == i) continue;
        if(dir == Reverse(i)) continue;
        DFS(next_Red, next_Blue, i, cnt+1);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str; cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
            if(map[i][j] == "R"){
                Red = {i, j};
                map[i][j] = ".";
            }
            if(map[i][j] == "B"){
                Blue = {i, j};
                map[i][j] = ".";
            }

        }
    }
    
    for(int d=0; d<4; d++){
        DFS(Red, Blue, d, 1);
    }
    
    if(Min == 999 || Min > 10){
        cout << -1;
    }
    else{
        cout << Min;
    }
}