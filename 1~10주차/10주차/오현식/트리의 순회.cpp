#include <iostream>

using namespace std;

typedef pair<int,int>   range;

int n;
int inorder[100001];    // idx: 1~100000
int postorder[100001];
int preorder[100001];
int indexOfPreorder=1;

void getPreorder(range rangeOfInorder, range rangeOfPostorder){
    
    int root = postorder[rangeOfPostorder.second];
    preorder[indexOfPreorder++] = root;
    int indexOfRootInInorder = rangeOfInorder.first;
    for(; indexOfRootInInorder<=rangeOfInorder.second ; indexOfRootInInorder++){
        if(inorder[indexOfRootInInorder]==root) break;
    }
    if(indexOfRootInInorder>rangeOfInorder.first) getPreorder({rangeOfInorder.first,indexOfRootInInorder-1},{rangeOfPostorder.first,rangeOfPostorder.first+indexOfRootInInorder-rangeOfInorder.first-1});
    if(indexOfRootInInorder<rangeOfInorder.second) getPreorder({indexOfRootInInorder+1,rangeOfInorder.second},{rangeOfPostorder.first+indexOfRootInInorder-rangeOfInorder.first,rangeOfPostorder.second-1});
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>inorder[i];
    for(int i=1;i<=n;i++)   cin>>postorder[i];
    getPreorder({1,n},{1,n});
    for(int i=1;i<=n;i++)   cout<<preorder[i]<<" ";
    return 0;
}
