#include <iostream>

const int MAX = 100001;
using namespace std;

int n;
int in[MAX], post[MAX];
int idx[MAX];

void preorder(int S_in, int E_in, int S_post, int E_post){
    if(S_in > E_in || S_post > E_post)
        return;
    
    cout << post[E_post] << " ";
    int root_idx = idx[post[E_post]];
    int size = root_idx - S_in;

    preorder(S_in, root_idx-1, S_post, S_post+size-1);
    preorder(root_idx+1, E_in, S_post+size, E_post-1);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(int i=0; i<n; i++){
        cin >> post[i];
    }

    preorder(0, n-1, 0, n-1);
}