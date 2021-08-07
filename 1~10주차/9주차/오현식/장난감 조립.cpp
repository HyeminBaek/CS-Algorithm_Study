#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int,int>> graph[101]; //  idx: 1~100, <node, weight>
int numOfBasicComponent[101][101];  // [node][basicNode]
int inDegree[101];


int main(int argc, const char * argv[]) {
    vector<int> nodefBasicComponent;
    queue<int> que;
    int X, Y, K;
    cin>>N>>M;  //  N:완제품 1~N-1:부품
    for(int i=0;i<M;i++){
        cin>>X>>Y>>K;
        graph[Y].push_back(make_pair(X,K));
        inDegree[X]++;
    }
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            numOfBasicComponent[i][i]=1;
            nodefBasicComponent.push_back(i);
            que.push(i);
        }
    }
    for(int i=0;i<N;i++){
        int cur = que.front();
        que.pop();
        
        for(int j=0;j<graph[cur].size();j++){
            int next = graph[cur][j].first;
            int weight = graph[cur][j].second;
            
            for(int k=0;k<nodefBasicComponent.size();k++){
                int basicComponenet = nodefBasicComponent[k];
                numOfBasicComponent[next][basicComponenet] += numOfBasicComponent[cur][basicComponenet]*weight;
            }
            if(--inDegree[next]==0) que.push(next);
        }
    }
    for(int i=1;i<=100;i++){
        if(numOfBasicComponent[N][i]!=0)    cout<<i<<" "<<numOfBasicComponent[N][i]<<endl;
    }
    return 0;
}
