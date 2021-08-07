#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N;
int parent[10001];

int getDepth(int node)
{
    int depth=0;
    while(parent[node]!=0)
    {
        node=parent[node];
        depth++;
    }
    return depth;
}

int findLCA(int A, int B)
{
    int depthOfA = getDepth(A);
    int depthOfB = getDepth(B);
    while(depthOfA!=depthOfB)
    {
        if(depthOfA<depthOfB)
        {
            B=parent[B];
            depthOfB--;
        }
        else if(depthOfA>depthOfB)
        {
            A=parent[A];
            depthOfA--;
        }
    }
    while(A!=B)
    {
        A=parent[A];
        B=parent[B];
    }
    return A;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>N;
        memset(parent,0,sizeof(parent));
        for(int j=0;j<N-1;j++)
        {
            cin>>A>>B;
            parent[B]=A;
        }
        cin>>A>>B;
        printf("%d\n",findLCA(A,B));
    }
    return 0;
}
