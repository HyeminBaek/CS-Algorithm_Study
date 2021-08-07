#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x, y;
    Point(int X,int Y):x(X),y(Y){}
    bool operator<=(Point &r){
        return (x<=r.x && y<=r.y);
    }
};

int board[21][21];
vector<Point> impurities;

bool checkStarHorizontal(Point &leftTop, Point &rightBottom, Point &impurity){
    for(int c=leftTop.y;c<=rightBottom.y;c++)   if(board[impurity.x][c]==2) return false;
    return true;
}

bool checkStarVertical(Point &leftTop, Point &rightBottom, Point &impurity){
    for(int r=leftTop.x;r<=rightBottom.x;r++)   if(board[r][impurity.y]==2)    return false;
    return true;
}

bool checkStar(Point &leftTop, Point &rightBottom){
    int numOfStar=0;
    for(int r=leftTop.x;r<=rightBottom.x;r++){
        for(int c=leftTop.y;c<=rightBottom.y;c++)   if(board[r][c]==2)  numOfStar++;
    }
    return (numOfStar==1);
}

int devide(Point leftTop, Point rightBottom, int dir){  // <dir> -1: vertical, +1: horizontal
    bool isNoImpurity=true;
    bool isBaseCase=false;
    int answer=0;
    if(leftTop.x==rightBottom.x || leftTop.y==rightBottom.y)    isBaseCase=true;
    for(int i=0;i<impurities.size();i++){
        if(leftTop<=impurities[i] && impurities[i]<=rightBottom){
            isNoImpurity=false;
            switch(dir){
                case 1: // 수평 분할
                    if(impurities[i].x==leftTop.x || impurities[i].x==rightBottom.x)    continue;
                    if(!checkStarHorizontal(leftTop,rightBottom,impurities[i])) continue;
                    
                    if(isBaseCase)  answer+=devide(leftTop,Point(impurities[i].x-1,leftTop.y),-1)*devide(Point(impurities[i].x+1,leftTop.y),rightBottom,-1);
                    else    answer+=devide(leftTop,Point(impurities[i].x-1,rightBottom.y),-1)*devide(Point(impurities[i].x+1,leftTop.y),rightBottom,-1);
                    break;
                case -1: // 수직 분할
                    if(impurities[i].y==leftTop.y || impurities[i].y==rightBottom.y)    continue;
                    if(!checkStarVertical(leftTop,rightBottom,impurities[i]))   continue;
                    
                    if(isBaseCase)    answer+=devide(leftTop,Point(leftTop.x,impurities[i].y-1),1)*devide(Point(leftTop.x,impurities[i].y+1),rightBottom,1);
                    else    answer+=devide(leftTop,Point(rightBottom.x,impurities[i].y-1),1)*devide(Point(leftTop.x,impurities[i].y+1),rightBottom,1);
                    break;
            }
        }
    }
    if(isNoImpurity){
        if(checkStar(leftTop,rightBottom))  return 1;
        else return 0;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans=0;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
            if(board[i][j]==1)  impurities.push_back(Point(i,j));
        }
    }
    ans+=devide(Point(1,1),Point(N,N),1);
    ans+=devide(Point(1,1),Point(N,N),-1);
    if(ans==0)  cout<<-1;
    else    cout<<ans;
    return 0;
}
