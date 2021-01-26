#include <iostream>

using namespace std;

struct TREE{
    int data;
    TREE *left;
    TREE *right;
};

TREE *Insert(TREE *x, int node){
    if(x == NULL){
        x = new TREE;
        x->data = node;
        x->left = NULL;
        x->right = NULL;
    }
    else{
        if(node < x->data){
            if(x->left == NULL)
                return x->left = Insert(NULL, node);
            else
                return  Insert(x->left, node);
        }
        else{
            if(x->right == NULL)
                return x->right = Insert(NULL, node);
            else
                return Insert(x->right, node);
        }
    }

    return x;
}

void Postorder(TREE *tree){
    if(tree != NULL){
        Postorder(tree->left);
        Postorder(tree->right);
        cout << tree->data << "\n";
    }
}

int main(){
    int node;
    TREE *root = NULL;
    while(cin >> node){
        if(root == NULL)
            root = Insert(root, node);
        else
            Insert(root, node);
    }

    Postorder(root);
}