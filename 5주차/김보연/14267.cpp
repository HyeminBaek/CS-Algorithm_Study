//회사문화1
#include <iostream>
#include <vector>
using namespace std;

vector<int> emps[1000000];

void dfs(vector<int> *point,int st){
    for(int ii:emps[st]){
        point->at(ii)+=point->at(st);
        dfs(point,ii);
    }
}

int main(){
    int n,m,boss;
    cin>>n>>m;
    vector<int> point(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>boss;
        //상사의 직원들 달아주기
        if(boss!=-1) emps[boss-1].push_back(i);
    }
    
    int emp,p;
    for(int
    
     i=0; i<m; i++){
        cin>>emp>>p;
        point[emp-1]+=p;
    }
    dfs(&point,0);
    
    for(int i=0; i<n; i++)
        cout<<point[i]<<" ";

    return 0;
}
