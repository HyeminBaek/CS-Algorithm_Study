#include <iostream>

using namespace std;

int arr[5000];
bool check[400001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans = 0;            
    for(int i=0; i<n; i++){
        
        for(int j=0; j<i; j++){
            if(check[arr[i]-arr[j]+200000]){
                ans++;
                break;
            }
        }

        for(int j=0; j<=i; j++)
            check[arr[i]+arr[j]+200000] = true;
    }

    cout << ans;
    return 0;
}