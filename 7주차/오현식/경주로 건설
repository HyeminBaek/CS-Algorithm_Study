#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
enum class Dir{N=0,E=90,S=180,W=270};
int Cost[26][26][4];    //1~25, dir:0~4("Dir/90"->N,E,S,W)
struct state
{
    vector<int> pos;
    Dir dir;    //N:0,E:90,S:180,W:270
    int cost;
    state(vector<int> p,Dir d,int c):pos(p),dir(d),cost(c){}
};

vector<Dir> getNextDir(Dir dir)
{
    Dir d1 = dir;
    int tmp = (int)dir-90;
    if(tmp<0) tmp+=360;
    Dir d2 = (Dir)tmp;
    tmp = (int)dir+90;
    if(tmp>270) tmp-=360;
    Dir d3 = (Dir)tmp;
    vector<Dir> next={d2,d1,d3};
    return next;
}

vector<int> getNextPos(vector<int> pos, Dir dir)
{
    if(dir==Dir::N) pos[0]--;
    else if(dir==Dir::E)    pos[1]++;
    else if(dir==Dir::S)   pos[0]++;
    else if(dir==Dir::W)   pos[1]--;
    return pos;
}

int getNextCost(int cost, Dir now, Dir next)
{
    if(now==next)   cost+=100;
    else    cost+=600;
    return cost;
}

bool IsValid(vector<vector<int>> &board, vector<int> pos,int cost,Dir dir)
{
    int n = board.size(); 
    if(pos[0]<0||pos[0]>n-1) return false;
    if(pos[1]<0||pos[1]>n-1) return false;
    if(board[pos[0]][pos[1]])   return false;  
    if(Cost[pos[0]][pos[1]][(int)dir/90]>0 && cost>Cost[pos[0]][pos[1]][(int)dir/90])   return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 9999999;
    int n = board.size();
    vector<int> dest={n-1,n-1};
    state f1({0,1},Dir::E,100);
    state f2({1,0},Dir::S,100);
    queue<state> queue;
    if(!board[0][1])
    {
        Cost[0][1][1]=100;
        queue.push(f1);
    }
    if(!board[1][0])
    {
        Cost[1][0][2]=100;
        queue.push(f2);
    }
    while(!queue.empty())
    {
        state tmp = queue.front();
        queue.pop();
        if(tmp.pos==dest)   continue;
            
        vector<Dir> next = getNextDir(tmp.dir);
        for(int i=0;i<3;i++)
        {
            vector<int> pos = getNextPos(tmp.pos,next[i]);
            int cost = getNextCost(tmp.cost,tmp.dir,next[i]);
            if(IsValid(board,pos,cost,next[i]))
            {
                state sch = state(pos,next[i],cost);
                Cost[pos[0]][pos[1]][(int)next[i]/90]=cost;
                queue.push(sch);
            }
        }
    }
    for(int i=0;i<4;i++)    if(Cost[n-1][n-1][i])  answer=min(answer,Cost[n-1][n-1][i]);
    return answer;
}
