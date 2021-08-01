#include<iostream>
#include <set>
#include <string>
using namespace std;
 
set<string> s;
const int SIZE=4;
int arr[SIZE][SIZE];
 
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
 
void recur(int x, int y, string num)
{
    if(num.length()==7)
    {
        s.insert(num); return;
    }
    for(int k=0;k<4;k++)
    {
        int nx = x+dx[k],ny=y+dy[k];
        if(0<=nx&&nx<SIZE&&0<=ny&&ny<SIZE)
        {
            recur(nx,ny,num+to_string(arr[nx][ny]));
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
     
    for(test_case = 1; test_case <= T; ++test_case)
    { 
        s.clear();
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
                cin>>arr[i][j];
        }
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
                recur(i,j,to_string(arr[i][j]));
        }
        cout<<"#"<<test_case<<" "<<s.size()<<"\n";
    }
     
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
