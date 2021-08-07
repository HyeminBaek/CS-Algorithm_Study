#include<iostream>
 
using namespace std;
 
int N,M;
char arr[50][50];
 
bool sol(int i,int j)
{
    if(arr[i+1][j]=='#'&&arr[i][j+1]=='#'&&arr[i+1][j+1]=='#')
    {
        arr[i+1][j]='.',arr[i][j+1]='.',arr[i+1][j+1]='.'; return true;
    }
     
    return false;
}
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N>>M;
         
        int sum =0;
        for(int i =0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='#') sum++;
            }
        }
 
        for(int i=0;i<N-1;i++)
        {
            if(sum==0) break;
            for(int j=0;j<M-1;j++)
            {
                if(arr[i][j]=='#'){
                    bool result = sol(i,j);
                    if(result) sum-=4;
                }
            }
        }
        if(sum==0) cout<<"#"<<test_case<<" YES\n";
        else cout<<"#"<<test_case<<" NO\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
