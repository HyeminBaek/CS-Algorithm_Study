#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[50][50]; 
int visited[50][50];

void check(int i,int j, int N)
{
    queue<pair<int,int>> q; q.push({i,j});
    int dx[]={0,0,1,-1}; int dy[]={1,-1,0,0};
    
    visited[i][j]=0;
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second; q.pop();
        
        for(int k =0;k<4;k++)
        {
            int nx = x+dx[k],ny=y+dy[k];
            if(0<=nx&&nx<N&&0<=ny&&ny<N)
            {
                if(visited[nx][ny]==-1)
                {
                    if(visited[x][y] +1 < N/2)
                    {
                        visited[nx][ny]=visited[x][y]+1;
                    	q.push({nx,ny});
                    }
                }
            }
        }
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N; cin>>N;

        for(int i =0;i<N;i++)
        {
            for(int j =0;j<N;j++)
            {
                char c; cin>>c;
                map[i][j]=c-'0';
                visited[i][j]=-1;
            }
        }
        if(N>1)
        {
        	check(0,0, N); check(N-1,0, N);  check(0,N-1, N); check(N-1,N-1, N);
        }
        int sum =0;
        for(int i =0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(visited[i][j]==-1) sum+=map[i][j];
            }
        }
        cout<<"#"<<test_case<<" "<<sum<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
