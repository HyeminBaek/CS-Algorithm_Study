#include <iostream>

const int MAX = 11;
using namespace std;

int n;
int arr[MAX];
int order[4];    // 덧셈, 뺄셈, 곱셈, 나눗셈
int Max = -1e9, Min = 1e9;

void DFS(int idx, int num){
    if(idx == n){
        Max = max(Max, num);
        Min = min(Min, num);
        return;
    }

    if(order[0] != 0){
        order[0]--;
        DFS(idx+1, num+arr[idx]);
        order[0]++;
    }
    if(order[1] != 0){
        order[1]--;
        DFS(idx+1, num-arr[idx]);
        order[1]++;
    }
    if(order[2] != 0){
        order[2]--;
        DFS(idx+1, num*arr[idx]);
        order[2]++;
    }
    if(order[3] != 0){
        order[3]--;
        DFS(idx+1, num/arr[idx]);
        order[3]++;
    }

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >> order[0] >> order[1] >> order[2] >> order[3];

    DFS(1, arr[0]);
    cout << Max << "\n" << Min;
}