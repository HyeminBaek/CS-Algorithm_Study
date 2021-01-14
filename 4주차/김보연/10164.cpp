#include <iostream>
using namespace std;

//permutation with repetition (a+b)!/a!*b!
int permu(int a, int b){
    double factorial1 = 1;
    double factorial2 = 1;
    for(int i=1; i<=a+b; i++)
        factorial1*=i;
    for(int i=1; i<=a; i++)
        factorial2*=i;
    for(int i=1; i<=b; i++)
        factorial2*=i;
    return factorial1/factorial2;
}

int main()
{
    int n,m,k;
    int y,x;
    int ans=0;
    cin>>n>>m>>k;

    if(k==0){ 
        cout<<permu(n-1,m-1);
        return 0;
    }

    y = (k-1)/m; 
    x = (k-1)%m;
    ans = permu(y,x);

    if(n-1-y==0 || m-1-x==0){}
    else ans *= permu(n-1-y,m-1-x);
    cout<<ans;

    return 0;
}
