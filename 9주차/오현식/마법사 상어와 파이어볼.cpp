#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1}; //dir: 0 1 2 3 4 5 6 7
int dy[8] = {0,1,1,1,0,-1,-1,-1}; //dir: 0 1 2 3 4 5 6 7

struct FireBall{
    pair<int,int> pos;
    int m, s, d;
    FireBall(pair<int,int> Pos, int M, int S, int D):pos(Pos),m(M),s(S),d(D){}
    FireBall move(int N){
        int next_x = pos.first;
        int next_y = pos.second;
        for(int i=0;i<s;i++)
        {
            next_x += dx[d];
            next_y += dy[d];
            if(next_x<1)    next_x+=N;
            else if(next_x>N)   next_x-=N;
            if(next_y<1)    next_y+=N;
            else if(next_y>N)   next_y-=N;
        }
        return FireBall(make_pair(next_x,next_y),m,s,d);
    }
};

struct Map{
    vector<FireBall> map[51][51];   // idx: 1~50
    int N;
    Map(int n):N(n){}
    void push(FireBall fireBall){
        map[fireBall.pos.first][fireBall.pos.second].push_back(fireBall);
    }
    Map move(void){
        Map next_map(N);
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++){
                for(int i=0;i<map[r][c].size();i++) next_map.push(map[r][c][i].move(N));
            }
        }
        return next_map;
    }
    void fuseAll(void){
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++)   if(map[r][c].size()>=2)    fuse(r,c);
        }
    }
    void fuse(int r, int c){
        int m=0, s=0;
        bool isOdd=false, isEven=false;
        for(int i=0;i<map[r][c].size();i++){
            if(map[r][c][i].d%2==0) isEven=true;
            else    isOdd=true;
            m+=map[r][c][i].m;
            s+=map[r][c][i].s;
        }
        m/=5;
        s/=map[r][c].size();
        map[r][c].clear();
        if(m==0)    return;
        if(!(isOdd&&isEven)){
            for(int d=0;d<=6;d+=2)  map[r][c].push_back(FireBall(make_pair(r,c),m,s,d));
        }
        else{
            for(int d=1;d<=7;d+=2)  map[r][c].push_back(FireBall(make_pair(r,c),m,s,d));
        }
    }
    int getM(void){
        int m=0;
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++){
                for(int i=0;i<map[r][c].size();i++) m+=map[r][c][i].m;
            }
        }
        return m;
    }
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin>>N>>M>>K;
    Map map(N);
    int r, c, m, s, d;
    for(int i=0;i<M;i++){
        cin>>r>>c>>m>>s>>d;
        map.push(FireBall(make_pair(r,c),m,s,d));
    }
    for(int i=0;i<K;i++){
        map = map.move();
        map.fuseAll();
    }
    cout<<map.getM();
    return 0;
}
