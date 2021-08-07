#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int bitOfNum[10]={0b111101101101111,0b001001001001001,0b111001111100111,0b111001111001111,0b101101111001001,0b111100111001111,0b111100111101111,0b111001001001001,0b111101111101111,0b111101111001111};   // bit of 0~9
char board[6][36];  //board[i][j] i:1~5 j:1~35
double ans;

int getbitOfNthNum(int n){
    int pos=14;
    int bitOfNthNum=0;
    for(int r=1;r<=5;r++){
        for(int c=4*n-3;c<=4*n-1;c++){
            if(board[r][c]=='#'){
                bitOfNthNum |= (1<<pos);
            }
            pos--;
        }
    }
    return bitOfNthNum;
}

int main(int argc, const char * argv[]) {
    cin>>N;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=3*N+(N-1);j++)   cin>>board[i][j];
    }
    for(int i=1;i<=N;i++){
        int bitOfNthNum = getbitOfNthNum(i);
        bool isPossible=false;
        vector<int> candidate;
        double sumOfCandidate=0;
        for(int j=0;j<10;j++){
            if((bitOfNthNum|bitOfNum[j]) == bitOfNum[j]) {
                isPossible =true;
                candidate.push_back(j);
            }
        }
        for(int j=0;j<candidate.size();j++) sumOfCandidate+=candidate[j];
        if(candidate.size()!=0) ans += sumOfCandidate/candidate.size()*pow(10,N-i);
        if(!isPossible){
            cout<<-1;
            return 0;
        }
    }
    printf("%lf",ans);
    return 0;
}
