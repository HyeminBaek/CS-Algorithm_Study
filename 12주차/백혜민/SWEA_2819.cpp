#include<iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;
 
int map[4][4];
set<string> s;
 
void bfs(int i, int j)
{
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
     
    queue<pair<pair<int,int>,string>> q;
    q.push({{i,j},to_string(map[i][j])});
     
    while(!q.empty())
    {
        int x = q.front().first.first,y=q.front().first.second;
        string a = q.front().second; q.pop();
         
        if(a.length()==7)
            s.insert(a);
        else
        {
            for(int k=0;k<4;k++)
            {
                int nx = x+dx[k], ny=y+dy[k];
                if(0<=nx&&nx<4&&0<=ny&&ny<4)
                {
                    string temp = a+to_string(map[nx][ny]);
                    q.push({{nx,ny},temp});
                }
            }
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i =0;i<4;i++)
        {
            for(int j =0;j<4;j++)
                cin>>map[i][j];
        }
        s.clear();
        for(int i =0;i<4;i++)
        {
            for(int j =0;j<4;j++)
                bfs(i,j);
        }
         
        cout<<"#"<<test_case<<" "<<s.size()<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
