#include <iostream>
#include <algorithm>

using namespace std;

int T;
int A, B;

int getDepth(int node)
{
    int depth=0;
    while(node!=1)
    {
        node/=2;
        depth++;
    }
    return depth;
}

int findLCA(int A, int B)
{
    int depthOfA = getDepth(A);
    int depthOfB = getDepth(B);
    while(depthOfB!=depthOfA){
        B/=2;
        depthOfB--;
    }
    while(A!=B)
    {
        A/=2;
        B/=2;
    }
    return A;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>A>>B;
        if(A>B) swap(A,B);
        printf("%d\n",10*findLCA(A,B));
    }
    return 0;
}
