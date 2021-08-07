#include <iostream>

using namespace std;

int n, m;
int arr[10000];

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int count = 0;
    int left = 0, right = 0;
    int sum = 0;
    while(1){
        if(sum >= m)
            sum -= arr[left++];
        else if(right == n)
            break;
        else
            sum += arr[right++];
        
        if(sum == m)
            count++;
    }

    cout << count;
}