#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;

int main(int argc, const char * argv[]) {
    int board[4];
    int dp_max[4];
    int dp_min[4];
    int tmp_max[4];
    int tmp_min[4];
    cin>>N;
    for(int i=1;i<=3;i++)   cin>>board[i];
    copy(board,board+4,dp_max);
    copy(board,board+4,dp_min);
    for(int i=2;i<=N;i++){
        for(int j=1;j<=3;j++)   cin>>board[j];
        for(int j=1;j<=3;j++){
            switch(j){
                case 1:
                    tmp_max[j] = board[j] + max(dp_max[j],dp_max[j+1]);
                    tmp_min[j] = board[j] + min(dp_min[j],dp_min[j+1]);
                    break;
                case 2:
                    tmp_max[j] = board[j] + max(max(dp_max[j-1],dp_max[j]),dp_max[j+1]);
                    tmp_min[j] = board[j] + min(min(dp_min[j-1],dp_min[j]),dp_min[j+1]);
                    break;
                case 3:
                    tmp_max[j] = board[j] + max(dp_max[j-1],dp_max[j]);
                    tmp_min[j] = board[j] + min(dp_min[j-1],dp_min[j]);
                    break;
            }
        }
        copy(tmp_max,tmp_max+4,dp_max);
        copy(tmp_min,tmp_min+4,dp_min);
    }
    sort(dp_max+1,dp_max+4);
    sort(dp_min+1,dp_min+4);
    cout<<dp_max[3]<<" "<<dp_min[1];
    return 0;
}
