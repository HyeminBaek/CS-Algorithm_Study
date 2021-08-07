#include <iostream>
#include <vector>

using namespace std;

int n;

int main(){
    cin >> n;
    int s = 3, k = 4;

    // n이 있는 길이의 S()를 찾기
    while(s < n){
        s = (s*2) + k;
        k++;
    }
    k--;

    // n < 3 인 경우 break; -> moo
    while(n > 3){
        int prev = (s-k)/2;

        if(n <= prev){    //S(k-1)보다 작을 경우
            s = prev;
            k--;
        }
        else if((prev+k) < n){    // S(k-1) + k 보다 클 경우
            n -= (prev+k);
            s = prev;
            k--;
        }
        else{                     // S(k-1) < n < k 인 경우 첫번째 경우만 m이고 나머지는 o이 차지
            n -= prev;
            break;
        }
    }

    if (n== 1){
        cout << "m";
    }
    else
        cout << "o";

    return 0;
}