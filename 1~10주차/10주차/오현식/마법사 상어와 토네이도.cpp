#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int>   Pos;
#define ALPHA -1

int N;
int A[500][500];    // idx: 3~499
int dx[4] = {0,1,0,-1};  // 0:West 1:South 2:East 3:North
int dy[4] = {-1,0,1,0};  // 0:West 1:South 2:East 3:North
int amountOfSandScatteredOutside;
vector<pair<Pos,int>> percentageOfSandScattering = { {Pos(-2,0),2},{Pos(-1,-1),10},{Pos(-1,0),7},{Pos(-1,1),1},{Pos(0,-2),5},{Pos(1,-1),10},{Pos(1,0),7},{Pos(1,1),1},{Pos(2,0),2}, {Pos(0,-1),ALPHA} };

struct Tornado
{
    Pos pos;
    int dir;    // <dir> 0:West 1:South 2:East 3:North
    int cntOfRotate;
    int cntOfMoveAfterRotation;
    
    Tornado(Pos p, int d=0, int r=0, int m=0):pos(p),dir(d),cntOfRotate(r),cntOfMoveAfterRotation(m){}
    
    bool move(void){
        if(pos==Pos(1,1))   return false;
        
        pos = Pos(pos.first+dx[dir], pos.second+dy[dir]);
        cntOfMoveAfterRotation++;
        blow();
        if(cntOfMoveAfterRotation == 1+cntOfRotate/2){
            cntOfMoveAfterRotation=0;
            dir = (dir+1)%4;
            cntOfRotate++;
        }
        return true;
    }
    
    void blow(void){
        int amountOfSand = A[pos.first][pos.second];
        int amountOfSandScattered=0;
        
        for(int i=0;i<percentageOfSandScattering.size();i++){
            Pos dPos = percentageOfSandScattering[i].first;
            for(int r=0;r<dir;r++)  dPos = rotate(dPos);
            Pos posSandWillBeScattered = Pos(pos.first + dPos.first, pos.second + dPos.second);
            int percentage = percentageOfSandScattering[i].second;
            
            if(percentage==ALPHA){
                if(isOutOfBound(posSandWillBeScattered))    amountOfSandScatteredOutside += amountOfSand-amountOfSandScattered;
                else    A[posSandWillBeScattered.first][posSandWillBeScattered.second] += amountOfSand-amountOfSandScattered;
                return;
            }
            
            amountOfSandScattered += amountOfSand*percentage/100;
            if(isOutOfBound(posSandWillBeScattered))    amountOfSandScatteredOutside += amountOfSand*percentage/100;
            else    A[posSandWillBeScattered.first][posSandWillBeScattered.second] += amountOfSand*percentage/100;
            
        }
        A[pos.first][pos.second] = 0;
    }
    
    Pos rotate(Pos dPos){   // 반시계 방향 90도 회전
        return Pos(-dPos.second,dPos.first);
    }
    
    bool isOutOfBound(Pos pos){
        if(pos.first<1 || pos.first>N || pos.second<1 || pos.second>N)  return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)   cin>>A[i][j];
    }
    Tornado tornado(Pos(1+N/2,1+N/2));
    while(tornado.move()){}
    cout<<amountOfSandScatteredOutside;
    return 0;
}
