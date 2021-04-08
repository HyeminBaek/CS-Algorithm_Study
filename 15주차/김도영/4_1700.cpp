#include <iostream>
#include <algorithm>

const int MAX = 101;
using namespace std;

int n, k;
int multitab[MAX], plug[MAX];

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> multitab[i];
    }

    int ret = 0;
    for(int i=0; i<k; i++){
        bool flag = false;

        for(int j=0; j<n; j++){
            if(plug[j] == multitab[i]){
                flag = true;
                break;
            }
        }
        if(flag) continue;

        for(int j=0; j<n; j++){
            if(plug[j] == 0){
                plug[j] = multitab[i];
                flag = true;
                break;
            }
        }
        if(flag) continue;

        int idx, last = -1;
        for(int j=0; j<n; j++){
            int temp = 0;
            for(int l = i+1; l<=k; l++){
                if(plug[j] == multitab[l]){
                    break;
                }
                temp++;
            }
            if(last < temp){
                idx = j;
                last = temp;
            }
        }
        ret++;
        plug[idx] = multitab[i];
    }

    cout << ret;
}