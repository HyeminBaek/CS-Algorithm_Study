#include <iostream>
#include <algorithm>

const int MAX = 100001;
using namespace std;

int n;
int arr[MAX];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int left = 0, right = n-1;
    int ans = 2e9;
    pair<int, int> point;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(abs(sum) < ans){
            point = {left, right};
            ans = abs(sum);

            if(ans == 0)    
                break;
        }

        if(sum < 0)
            left++;
        else
            right--;
    }
    cout << arr[point.first] << " " << arr[point.second];
}