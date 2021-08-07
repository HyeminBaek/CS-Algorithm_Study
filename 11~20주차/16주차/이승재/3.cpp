#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    return a < b;
}

int main() {
    int N;
    cin >> N;

    int tmp;
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), compare);
    int left{0}, right{N-1}, answer[3]{0, 0, INT_MAX};
    while (left < right) {
        if (answer[2] > abs(vec[left] + vec[right])) {
            answer[0] = left;
            answer[1] = right;
            answer[2] = abs(vec[left] + vec[right]);
            if (vec[left] + vec[right] == 0)
                break;
        }
        if (vec[left] + vec[right] > 0)
            right -= 1;
        else
            left += 1;
    }
    cout <<vec[answer[0]] <<" "<< vec[answer[1]];
    return 0;
}
