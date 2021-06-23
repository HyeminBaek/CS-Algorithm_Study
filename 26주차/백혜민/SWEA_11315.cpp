#include<iostream>
#include <queue>
using namespace std;
 
int dx[] = {1,0,1,1};
int dy[]={0,1,1,-1};
 
bool check(char arr[20][20],int N,int i,int j)
{
    queue<pair<pair<int,int>,pair<int,int>>> q;
    for(int k=0;k<4;k++)
    {
        int nx = i+dx[k],ny=j+dy[k];
        if(0<=nx&&nx<N&&0<=ny&&ny<N)
        {
            if(arr[nx][ny]=='o') q.push({{nx,ny},{2,k}});
        }
    }
     
    while(!q.empty())
    {
        int x = q.front().first.first, y=q.front().first.second, sum= q.front().second.first, dir = q.front().second.second;
        q.pop();
         
        if(sum>=5) return true;
         
        int nx = x+dx[dir],ny= y+dy[dir];
        if(0<=nx&&nx<N&&0<=ny&&ny<N)
        {
            if(arr[nx][ny]=='o') q.push({{nx,ny},{sum+1,dir}});
        }
    }
    return false;
}
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N; cin>>N;
         
        char arr[20][20];
        for(int i =0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>arr[i][j];
            }
        }
         
        bool res = false;
        for(int i =0;i<N;i++)
        {
            if(res) break;
            for(int j =0;j<N;j++)
            {
                if(arr[i][j]=='o') 
                {
                    res =check(arr,N,i,j);
                }
                if(res) break;
            }
        }
         
        if(res) cout<<"#"<<test_case<<" YES\n";
        else cout<<"#"<<test_case<<" NO\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
