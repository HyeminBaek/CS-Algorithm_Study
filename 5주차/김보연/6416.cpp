//트리인가?
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int k=1;
    bool isTree=true;
    while(1)
    {   
        map<int,int> m; //외부에서 나를 가리키는 노드 저장
        set<int> s;
        int u=0,v=0;
        isTree=true;
        
        while(1)
        {
            cin>>u>>v; //u->v
            if(u==-1 && v==-1) return 0;
            if(!u && !v) break;
            if(!u && u==v) isTree=false;

            if(!m.count(v)){
                if(m.count(u) && m.at(u)==v)
                    isTree = false;
                else{
                    m.insert({v,u});
                    s.insert(u); //루트 후보들
                }
            }
            //날 가르키는게 또 나옴
            else isTree = false;
        }
        //루트 검사
        int root_cnt = 0;
        for(int r : s)
            if(!m.count(r)) root_cnt++;
        
        if(isTree && root_cnt==1 || s.empty()) cout<<"Case "<<k<<" is a tree.\n";
        else cout<<"Case "<<k<<" is not a tree.\n";
        k++;
    }
    return 0;
}
