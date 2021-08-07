#include <iostream>

using namespace std;

int S[27];

char Moo(int N){
    if(N<=3){
        if(N==1)    return 'm';
        else return 'o';
    }
    
    int k=0;
    for(;k<=26;k++){
        if(N<S[k])  break;
    }
    
    if(N>=S[k-1]+k+4)   return Moo(N-S[k-1]-k-3);
    else if(N<=S[k-1]+k+3){
        if(N==S[k-1]+1) return 'm';
        else return 'o';
    }
    return 'x';
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int k=0;
    S[k]=3;
    while(S[k]<1000000000){
        S[k+1] = 2*S[k]+(k+4);
        k++;
    }
    cout<<Moo(N);
    return 0;
}
