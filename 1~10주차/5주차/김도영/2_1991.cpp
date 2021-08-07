#include <iostream>

using namespace std;

int tree[26][2];

void Preorder(int node){
    if(node == -1) return;
    
    cout << char(node+'A');
    Preorder(tree[node][0]);
    Preorder(tree[node][1]);
}

void Inorder(int node){
    if(node == -1) return;

    Inorder(tree[node][0]);
    cout << char(node+'A');
    Inorder(tree[node][1]);
}

void Postorder(int node){
    if(node == -1) return;

    Postorder(tree[node][0]);
    Postorder(tree[node][1]);
    cout << char(node+'A');
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        char root, left, right;
        cin >> root >> left >> right;

        tree[root-'A'][0] = left != '.' ? left-'A' : -1;
        tree[root-'A'][1] = right != '.' ? right-'A' : -1;
    }

    Preorder(0);
    cout << "\n";
    Inorder(0);
    cout << "\n";
    Postorder(0);
}