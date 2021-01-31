#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0,tot=0;
    cin >> n;

    vector<pii> input(n);
    int x,y;
    for(int i=0; i<n; i++){
        cin>>x; cin>>y;

        //첫 입력값이 더 크면 바뀌주기
        if(y<x) input[i]={y,x};
        else input[i]={x,y};
    }
    sort(input.begin(), input.end());

    int st=input[0].first,end=input[0].second;
    for(int i=1; i<n; i++){
        x = input[i].first; y = input[i].second;
        if(end>=x){
            if(y > end) end = y;
        }
        else{
            tot+=end-st;
            st = x; end = y;
        }
    }
    tot+=end-st;
    cout<<tot;
    return 0;
}
