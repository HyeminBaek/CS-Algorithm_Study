#include <iostream>

using namespace std;

int d, k;
int a[31];
int b[31];

int main(){
    cin >> d >> k;

    a[1] = 1;
    a[2] = 0;

    b[1] = 0;
    b[2] = 1;

    for(int i=3; i<31; i++){
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-1] + b[i-2];
    }

    for(int x=1; x<=k; x++){
        if((k-a[d]*x)%b[d] == 0){
            cout << x << "\n" << (k-a[d]*x)/b[d];
            break;
        }
    }
}