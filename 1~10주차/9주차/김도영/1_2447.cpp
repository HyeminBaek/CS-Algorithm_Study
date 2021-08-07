#include <iostream>

using namespace std;

void Star(int y, int x, int num){
    if((y/num)%3 == 1 && (x/num)%3 == 1)
        cout << ' ';
    
    else{
        if(num/3 == 0)
            cout << '*';
        else
            Star(y, x, num/3);
    }
}   


int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Star(i, j, n);
        }
        cout << "\n";
    }
}