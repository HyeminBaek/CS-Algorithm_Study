#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int,int>   Pos;

int N, Q, L;
int lengthOfMap;
int A[65][65];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[65][65];

void rotateSection(Pos leftTop, int lengthOfSection){
    int R[65][65];
    int beginOfRow = leftTop.first, endOfRow = leftTop.first + lengthOfSection-1;
    int beginOfCol = leftTop.second, endOfCol = leftTop.second + lengthOfSection-1;
    for(int i=0;i<lengthOfSection;i++){
        for(int j=0;j<lengthOfSection;j++)   R[beginOfRow+j][endOfCol-i] = A[beginOfRow+i][beginOfCol+j];
    }
    for(int i=beginOfRow;i<=endOfRow;i++){
        for(int j=beginOfCol;j<=endOfCol;j++)   A[i][j] = R[i][j];
    }
}

void rotate(int lengthOfSection){
    for(int i=1;i<=lengthOfMap;i+=lengthOfSection){
        for(int j=1;j<=lengthOfMap;j+=lengthOfSection) rotateSection(Pos(i,j),lengthOfSection);
    }
}

bool isOutOfBound(int x, int y){
    if(x<1||x>lengthOfMap||y<1||y>lengthOfMap)  return true;
    return false;
}

bool isMeltable(int x,int y){
    int numOfIce=0;
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(isOutOfBound(next_x,next_y)) continue;
        if(A[next_x][next_y]>0)    numOfIce++;
    }
    return (numOfIce<3);
}

void melt(void){
    int M[65][65];
    for(int i=1;i<=lengthOfMap;i++){
        for(int j=1;j<=lengthOfMap;j++){
            if(isMeltable(i,j) && A[i][j]>0) M[i][j] = A[i][j]-1;
            else M[i][j] = A[i][j];
        }
    }
    for(int i=1;i<=lengthOfMap;i++){
        for(int j=1;j<=lengthOfMap;j++) A[i][j] = M[i][j];
    }
}

int getNumOfIce(void){
    int numOfIce=0;
    for(int i=1;i<=lengthOfMap;i++){
        for(int j=1;j<=lengthOfMap;j++) numOfIce+=A[i][j];
    }
    return numOfIce;
}

int getSpaceOfIce(int x, int y){
    visited[x][y]=true;
    int spaceOfIce=1;
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(isOutOfBound(next_x,next_y) || visited[next_x][next_y] || A[next_x][next_y]==0) continue;
        spaceOfIce += getSpaceOfIce(next_x,next_y);
    }
    return spaceOfIce;
}

int getSpaceOfBigestIce(void){
    int spaceOfBiggestIce=0;
    for(int i=1;i<=lengthOfMap;i++){
        for(int j=1;j<=lengthOfMap;j++) if(!visited[i][j] && A[i][j]>0)  spaceOfBiggestIce = max(spaceOfBiggestIce, getSpaceOfIce(i,j));
    }
    return spaceOfBiggestIce;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>Q;
    lengthOfMap = pow(2,N);
    for(int i=1;i<=lengthOfMap;i++){
        for(int j=1;j<=lengthOfMap;j++) cin>>A[i][j];
    }
    for(int i=0;i<Q;i++){
        cin>>L;
        rotate(pow(2,L));
        melt();
    }
    cout<<getNumOfIce()<<endl;
    cout<<getSpaceOfBigestIce();
    return 0;
}
