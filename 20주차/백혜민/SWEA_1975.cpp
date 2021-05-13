#include<iostream>
 
using namespace std;
 
int sudoku[9][9];
 
bool garo()
{
    bool result = true;
     
    for(int i =0;i<9;i++)
    {
        int sum =0;
        for(int j =0;j<9;j++)
        {
            sum+=sudoku[i][j];
        }
         
        if(sum!=45)
        {
            result = false; break;
        }
    }
     
    return result;
}
bool sero()
{
    bool result = true;
     
    for(int i =0;i<9;i++)
    {
        int sum =0;
        for(int j =0;j<9;j++)
        {
            sum+=sudoku[j][i];
        }
         
        if(sum!=45)
        {
            result = false; break;
        }
    }
     
    return result;
}
bool jeon()
{
    for(int i =0;i<9;i+=3)//행
    {
        for(int j=0;j<9;j+=3)//열
        {
            int sum =0;
            for(int k =i;k<i+3;k++)
            {
                for(int l =j;l<j+3;l++)
                {
                    sum+=sudoku[k][l];
                }
            }
            if(sum!=45)
            {
                return false;
            }
        }
    }
    return true;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;cin>>T;
     
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i =0;i<9;i++)
        {
            for(int j =0;j<9;j++)
                cin>>sudoku[i][j];
        }
         
        cout<<"#"<<test_case<<" ";
        bool flag = sero();
        if(flag) 
        {
            flag = garo();
            if(flag) {
                flag = jeon();
                 
                if(flag) cout<<1<<"\n";
                else cout<<0<<"\n";
            }
            else cout<<0<<"\n";
        }
        else cout<<0<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
