#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int remaningTime[10001];
int inDegree[10001];
bool isProceeding[10001];
vector<int> graph[10001];
int N;

struct compare
{
    bool operator()(int n1, int n2){
        return remaningTime[n1] > remaningTime[n2];
    }
};

priority_queue<int,vector<int>,compare> pq;

int main(int argc, const char * argv[]) {
    int answer=0;
    int numOfPrecedingWork;
    int precedingWork;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>remaningTime[i];
        cin>>numOfPrecedingWork;
        for(int j=0;j<numOfPrecedingWork;j++){
            cin>>precedingWork;
            graph[precedingWork].push_back(i);
        }
        inDegree[i] += numOfPrecedingWork;
    }
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            isProceeding[i]=true;
            pq.push(i);
        }
    }
    for(int i=0;i<N;i++){
        int currentWork = pq.top();
        pq.pop();
        isProceeding[currentWork]=false;
        answer += remaningTime[currentWork];
        for(int j=1;j<=N;j++)   if(isProceeding[j]) remaningTime[j] -= remaningTime[currentWork];
        remaningTime[currentWork]=0;
        
        for(int j=0;j<graph[currentWork].size();j++){
            int nextWork = graph[currentWork][j];
            if(--inDegree[nextWork]==0){
                isProceeding[nextWork]=true;
                pq.push(nextWork);
            }
        }
    }
    cout<<answer;
    return 0;
}
