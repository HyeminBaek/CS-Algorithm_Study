#include <iostream>

using namespace std;

char map[2188][2188];   // idx: 1 ~ 2187

void setBlank(int x, int y, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[x+i][y+j] = ' ';
        }
    }
}

void setStart(int x,int y,int N){
    if(N==1){
        map[x][y]='*';
        return;
    }
    for(int i=0;i<N;i+=N/3){
        for(int j=0;j<N;j+=N/3){
            if(i==N/3 && j==N/3)    {
                setBlank(x+i,y+i,N/3);
                continue;
            }
            setStart(x+i,y+j,N/3);
        }
    }
}

void printStart(int N){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    setStart(1,1,N);
    printStart(N);
    return 0;
}
