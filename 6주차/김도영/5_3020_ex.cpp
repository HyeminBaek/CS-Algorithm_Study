#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, h;
    cin >> n >> h;

    vector<int> bottom(n/2), top(n/2);
    for(int i=0; i<n/2; i++){
        cin >> bottom[i] >> top[i];
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int result = 1e9;
    int cnt = 1;
    for(int i=1; i<=h; i++){
        /*
            lower_bound : key값 이상인 첫 번째 원소의 위치(iterator 값)
            upper_bound : key값 초과하는 첫 번째 원소의 위치(iterator 값)
        */
        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
        temp += top.size() - (upper_bound(top.begin(), top.end(), h-i) - top.begin());

        if(result == temp){
            cnt++;
        }
        else if(temp < result){
            result = temp;
            cnt = 1;
        }
    }
    
    cout << result << " " << cnt;
}