//
//  main.cpp
//  이진 검색 트리
//
//  Created by 오현식 on 2021/01/24.
//

#include <iostream>

using namespace std;

struct Btree
{
    int data;
    Btree *left, *right;
    
    Btree(int d=0, Btree *l=nullptr, Btree *r=nullptr):data(d),left(l),right(r){}
    
    void insert(int data)
    {
        if(data<this->data)
        {
            if(left==nullptr)   left = new Btree(data);
            else    left->insert(data);
        }
        else
        {
            if(right==nullptr)  right = new Btree(data);
            else    right->insert(data);
        }
    }
    
    void postfix(void)  // LRV
    {
        if(left!=nullptr)   left->postfix();
        if(right!=nullptr)  right->postfix();
        cout<<data<<endl;
    }
};

int main(int argc, const char * argv[]) {
    int node;
    cin>>node;
    Btree btree(node);
    while(cin>>node)    btree.insert(node);
    btree.postfix();
    return 0;
}
