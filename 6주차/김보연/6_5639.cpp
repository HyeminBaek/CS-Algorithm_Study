#include <iostream>
#include <map>
using namespace std;

struct node {
    int left=0;
    int right=0;
};

// map<int,node> tree; //맵쓰면 시간초과...
int tree[1000000][2];

void post(int root)
{
    if(root==0) return;
    post(tree[root][0]);
    post(tree[root][1]);
    cout<<root<<"\n";
}

void insert(int root, int node)
{
    if(root>node) {
        if(tree[root][0]==0) {
            tree[root][0]=node;
            return;
        }
        else insert(tree[root][0], node);
    }
    else {
        if(tree[root][1]==0) {
            tree[root][1]=node;
            return;
        }
        else insert(tree[root][1], node);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,root=-1;
    while(cin>>n){
        if(n == -1) break;
        if(root==-1) {
            root=n;
        }
        else insert(root,n);
    }
    post(root);
    return 0;
}
