#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int k;
vector<int> graph[11];    // idx: 1~10
int answer_min[11];
int answer_max[11];
int inDegree_min[11]; // idx: 1~10
int inDegree_max[11]; // idx: 1~10
priority_queue<int,vector<int>,greater<int>>    minHeap;
priority_queue<int> maxHeap;

int main(int argc, const char * argv[]) {
    char relation;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>relation;
        if(relation=='<'){
            inDegree_min[i+1]++;
            inDegree_max[i+1]++;
            graph[i].push_back(i+1);
        }
        else if(relation=='>'){
            inDegree_min[i]++;
            inDegree_max[i]++;
            graph[i+1].push_back(i);
        }
    }
    
    int num=0;
    for(int i=1;i<=k+1;i++) if(inDegree_min[i]==0)  minHeap.push(i);
    for(int i=0;i<k+1;i++)
    {
        int cur = minHeap.top();
        minHeap.pop();
        answer_min[cur] = num++;
        
        for(int j=0;j<graph[cur].size();j++){
            int next = graph[cur][j];
            if(--inDegree_min[next] == 0)   minHeap.push(next);
        }
    }
    
    num=9-k;
    for(int i=1;i<=k+1;i++) if(inDegree_max[i]==0)  maxHeap.push(i);
    for(int i=0;i<k+1;i++)
    {
        int cur = maxHeap.top();
        maxHeap.pop();
        answer_max[cur] = num++;
        
        for(int j=0;j<graph[cur].size();j++){
            int next = graph[cur][j];
            if(--inDegree_max[next] == 0)   maxHeap.push(next);
        }
    }
    for(int i=1;i<=k+1;i++) cout<<answer_max[i];
    cout<<endl;
    for(int i=1;i<=k+1;i++) cout<<answer_min[i];
    return 0;
}
