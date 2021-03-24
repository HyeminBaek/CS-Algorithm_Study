#include <iostream>

using namespace std;


int gcd(int x, int y){
    if(y == 0){
        return x;
    }

    return gcd(y, x%y);
}

int main(){
    int G, L;
    long long ret1, ret2;
    
    cin >> G >> L;
    L /= G;

    int x;
    for(int i=1; i*i <= L; i++){
        //약수 중에서 서로소인 수 찾기
        if(L%i == 0 && gcd(i, L/i) == 1){
            x = i;
        }
    }
    ret1 = G*x;
    ret2 = G*(L/x);
    cout << ret1 << " " << ret2;
}