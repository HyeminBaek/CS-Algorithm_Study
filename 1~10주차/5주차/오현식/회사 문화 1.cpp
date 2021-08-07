#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> tree[100001];
int confident[100001];

void praise(int numOfEmployee)
{
    for(int i=0;i<tree[numOfEmployee].size();i++)
    {
        confident[tree[numOfEmployee][i]] += confident[numOfEmployee];
        praise(tree[numOfEmployee][i]);
    }
}

int main(int argc, const char * argv[]) {
    int i, w;
    int superior;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>superior;
        if(superior!=-1)    tree[superior].push_back(i);    // n(1): boss
    }
    for(int j=0;j<m;j++)
    {
        cin>>i>>w;
        confident[i] += w;
    }
    praise(1);
    for(int i=1;i<=n;i++)   cout<<confident[i]<<" ";
    return 0;
}
