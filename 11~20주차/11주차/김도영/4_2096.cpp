#include <iostream>

const int MAX = 100001;
using namespace std;

int n;
int map[MAX][3];
int pre_max[3], pre_min[3];
int cur_max[3], cur_min[3];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> map[i][j];
            if(i == 0){
                pre_max[j] = map[0][j];
                pre_min[j] = map[0][j];
            }
        }
    }

    for(int i=1; i<n; i++){
        cur_max[0] = max(pre_max[0], pre_max[1]) + map[i][0];
        cur_min[0] = min(pre_min[0], pre_min[1]) + map[i][0];

        cur_max[1] = max(pre_max[0], max(pre_max[1], pre_max[2])) + map[i][1];
        cur_min[1] = min(pre_min[0], min(pre_min[1], pre_min[2])) + map[i][1];
        
        cur_max[2] = max(pre_max[1], pre_max[2]) + map[i][2];
        cur_min[2] = min(pre_min[1], pre_min[2]) + map[i][2];

        for(int j=0; j<3; j++){
            pre_min[j] = cur_min[j];
            pre_max[j] = cur_max[j];
        }
    }
    
    int ans_max = max(pre_max[0], max(pre_max[1], pre_max[2]));
    int ans_min = min(pre_min[0], min(pre_min[1], pre_min[2]));

    cout << ans_max << " " << ans_min;
    return 0;
}