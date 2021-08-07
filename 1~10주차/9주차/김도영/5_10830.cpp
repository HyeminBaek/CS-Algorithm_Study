#include <iostream>

using namespace std;

long long n, b;
int A[5][5], ret[5][5], temp[5][5];    // %1000

/* 
빠른 거듭제곱 알고리즘
N이 홀수이면 A^N을 A*A^(N-1)로 바꾸고 A를 결과값에 곱하기

N이 짝수이면 A^N을 (A^2)^(N/2) 즉 A를 제곱하고 N을 2로 나눈다

N = 0이면 종료

*/

void Matrix_mul(int a[5][5], int b[5][5]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] =0;
            for(int k=0; k<n; k++){
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = temp[i][j];
        }
    }
}

int main(){
    cin >> n >> b;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
        ret[i][i] = 1;
    }

    while (b > 0){
        if (b%2 == 1){
            Matrix_mul(ret, A);
        }    
        Matrix_mul(A, A);
        
        b /= 2;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << ret[i][j] << " ";
        }
        if(i == n-1) break;
        cout << "\n";
    }
}