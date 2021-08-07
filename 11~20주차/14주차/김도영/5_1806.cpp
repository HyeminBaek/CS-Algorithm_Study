#include <iostream>

const int MAX = 100001;
using namespace std;

int n, s, ans = 987654321;
int arr[MAX];

int main(){
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int sum = arr[0];
    while(left <= right && right < n){
        if(sum < s){
            sum += arr[++right];
        }
        else{
            ans = min(ans, right-left+1);
            if(s < sum){
                sum -= arr[left++];
            }
            else{
                sum += arr[++right];
            }
        }
    }

    if(ans == 987654321)
        cout << 0;
    else
        cout << ans;
}
