//
//  main.cpp
//  트리 순회
//
//  Created by 오현식 on 2021/01/20.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Edges[26];  // 0(A)~25(Z)

struct Btree
{
    int data;   //  0(A) ~ 25(Z)
    Btree *left, *right;
    Btree(int d=-1, Btree *l=nullptr, Btree *r=nullptr):data(d),left(l),right(r){}
    
    void makeBtree(int root)    // root: 0(A)~25(Z)
    {
        data=root;
        if(Edges[root][0]!='.'-'A')
        {
            left = new Btree(Edges[root][0]);
            left->makeBtree(Edges[root][0]);
        }
        if(Edges[root][1]!='.'-'A')
        {
            right = new Btree(Edges[root][1]);
            right->makeBtree(Edges[root][1]);
        }
    }
    void prefix(void)
    {
        cout<<(char)('A'+data);
        if(left!=nullptr)    left->prefix();
        if(right!=nullptr)  right->prefix();
    }
    void inorder(void)
    {
        if(left!=nullptr)   left->inorder();
        cout<<(char)('A'+data);
        if(right!=nullptr)  right->inorder();
    }
    void postfix(void)
    {
        if(left!=nullptr)  left->postfix();
        if(right!=nullptr)  right->postfix();
        cout<<(char)('A'+data);
    }
};

int main(int argc, const char * argv[]) {
    char root, left, right;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>root>>left>>right;
        Edges[root-'A'].push_back(left-'A');
        Edges[root-'A'].push_back(right-'A');
    }
    Btree btree(0);
    btree.makeBtree(0);
    btree.prefix();
    cout<<endl;
    btree.inorder();
    cout<<endl;
    btree.postfix();
    return 0;
}
