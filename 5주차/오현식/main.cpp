//
//  main.cpp
//  트리인가
//
//  Created by 오현식 on 2021/01/22.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<pair<int,int>> edges;
map<int,int> inDegree;
int maximumNode;

bool isTree(void)
{
    int numOfRoot=0;
    int root=0;
    vector<int> tree[maximumNode+1];
    set<int> numOfNodes;
    queue<int> que;
    
    if(edges.size()==0) return true;    // node가 0개인 경우
    
    for(int i=0;i<edges.size();i++)
    {
        tree[edges[i].first].push_back(edges[i].second);    // make tree
        numOfNodes.insert(edges[i].first);  // make set of node
        numOfNodes.insert(edges[i].second);
        
        if(inDegree[edges[i].first]==0 && root!=edges[i].first) // root node
        {
            numOfRoot++;
            root=edges[i].first;
        }
        
        if(inDegree[edges[i].second]>1)     return false;   // condition 2
    }
    if(numOfRoot>1)     return false;   // condition 1
    
    que.push(root);
    while(!que.empty())
    {
        int current = que.front();
        que.pop();
        
        if(numOfNodes.find(current)==numOfNodes.end())  return false;   // condition 3 : 2개이 상의 경로가 존재하는 경우
        numOfNodes.erase(current);
        
        for(int i=0;i<tree[current].size();i++)     que.push(tree[current][i]);
    }
    if(numOfNodes.size()!=0)    return false;
    
    return true;
}

int main(int argc, const char * argv[]) {
    int u, v;
    int k=0;
    bool isOver=false;
    while(true)
    {
        k++;
        edges.clear();
        inDegree.clear();
        maximumNode = 0;
        
        while(true)
        {
            cin>>u>>v;
            if(u==0 && v==0)    break;
            if(u==-1 && v==-1)
            {
                isOver=true;
                break;
            }
            inDegree[v]++;
            maximumNode = max(maximumNode,u);
            maximumNode = max(maximumNode,v);
            edges.push_back(make_pair(u,v));
        }
        if(isOver)  break;
        
        if(isTree())    cout<<"Case "<<k<<" is a tree."<<endl;
        else    cout<<"Case "<<k<<" is not a tree."<<endl;
    }
    
    return 0;
}
