#include<iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int queen[8];

bool check(int row, int col){
    for(int i=0; i<row; i++){
        int position = queen[i];    // 현재 행의 퀀의 column 위치
        
        //같은 열에 queen을 놓을 수 없다.
        if(col == position)
            return false;
        
        //대각선도 불가능
        //두 퀀의 열의 차이와 행의 차이가 같다면 같은 대각선에 위치한다는 의미
        int a = abs(position - col);
        int b = row - i;
        if(a == b)
            return false;
    }
    
    return true;
}

int PlaceQueen(int row){
    if(row == n){
        return 1;
    }
    
    int cnt = 0;
    for(int col = 0; col < n; col++){
        if(check(row, col) == true){
            queen[row] = col;
            cnt += PlaceQueen(row+1);
        }
    }
    
    return cnt;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(queen, 0, sizeof(queen));
		cin >> n;
		int ans = PlaceQueen(0);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}