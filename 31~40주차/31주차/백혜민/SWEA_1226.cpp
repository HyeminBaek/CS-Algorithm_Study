#include<iostream>
#include <string>
#include <queue>
using namespace std;
 
int arr[16][16];
int sx,sy;
 
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
 
bool bfs()
{
    bool visited[16][16]={false,};
    visited[sx][sy]=true;
     
    queue<pair<int,int>> q;
    q.push({sx,sy});
     
    while(!q.empty())
    {
        int x = q.front().first, y= q.front().second; q.pop();
         
        for(int k=0;k<4;k++)
        {
            int nx = x+dx[k],ny=y+dy[k];
             
            if(0<=nx&&nx<16&&0<=ny&&ny<16)
            {
                if(!visited[nx][ny]&&(arr[nx][ny]==0||arr[nx][ny]==3))
                {
                    visited[nx][ny]=true;
                    if(arr[nx][ny]==0) q.push({nx,ny});
                    else return true;
                }
            }
        }
    }
    return false;
}
int main(int argc, char** argv)
{
    int test_case;
 
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        int t; cin>>t;
        //16*16 행렬
        for(int i=0;i<16;i++)
        {
            string s; cin>>s;
            for(int j=0;j<s.length();j++)
            {
                arr[i][j]=s[j]-'0';
                if(arr[i][j]==2) sx= i,sy=j;
            }
        }
         
        cout<<"#"<<test_case<<" "<<bfs()<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
