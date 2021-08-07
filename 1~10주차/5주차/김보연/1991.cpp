#include <iostream>
#include <map>
using namespace std;

struct node{
    char left='.';
    char right='.';
};

map<char,node> m;
void pre(char root)
{
    if(root=='.') return;
    cout<<root;
    pre(m[root].left);
    pre(m[root].right);
}

void in(char root)
{
    if(root=='.') return;
    in(m[root].left);
    cout<<root;
    in(m[root].right);
}

void post(char root)
{
    if(root=='.') return;
    post(m[root].left);
    post(m[root].right);
    cout<<root;
}

int main(){
    int n=0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        char root,l,r;
        cin>>root>>l>>r;

        if(l!='.')
            m[root].left = l;
        if(r!='.')
            m[root].right = r;
    }
    pre('A');
    cout<<"\n";
    in('A');
    cout<<"\n";
    post('A');
    return 0;
}
