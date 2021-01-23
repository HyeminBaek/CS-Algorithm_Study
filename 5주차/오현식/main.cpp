//
//  main.cpp
//  떡 먹는 호랑이
//
//  Created by 오현식 on 2021/01/17.
//

#include <iostream>

using namespace std;

int D, K;
int A[31];
int B[31];

int main(int argc, const char * argv[]) {
    cin>>D>>K;
    A[1] = 1;
    B[1] = 0;
    A[2] = 0;
    B[2] = 1;
    for(int i=3;i<=D;i++)   //      ?A + ?B = K <-> ?B = K - ?A, (1<=A<=B)
    {
        A[i] = A[i-1] + A[i-2];
        B[i] = B[i-1] + B[i-2];
    }
    for(int a=1;a<=K;a++)
    {
        if((K-A[D]*a)%B[D]==0){
            cout<<a<<endl<<(K-A[D]*a)/B[D];
            break;
        }
    }
    return 0;
}
