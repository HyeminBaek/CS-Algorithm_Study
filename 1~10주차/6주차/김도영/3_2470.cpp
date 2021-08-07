#include <iostream>
#include <cmath>
#include <algorithm>

const int MAX = 100000;
using namespace std;

int n;
int arr[MAX];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int ans = 2e9;
    pair<int, int> point;
    int left = 0, right = n-1;

    while(left < right){
        int temp = arr[right] + arr[left];
        if(abs(temp) < ans){
            ans = abs(temp);
            point.first = left;
            point.second = right;
            if(ans == 0) break;
        }

        if(temp < 0)
            left++;
        else
            right--;
    }

    cout << arr[point.first] << " " << arr[point.second]  << "\n";
    return 0;
}