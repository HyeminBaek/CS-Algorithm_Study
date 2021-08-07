#include <string>
#include <vector>

using namespace std;
pair<int,int> arr[10] = {{4,2}, {1,1}, {1,2}, {1,3}, {2,1}, {2,2},{2,3},{3,1}, {3,2}, {3,3}};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> cur_left = {4,1};
    pair<int,int> cur_right = {4,3};
    for(int i = 0; i<numbers.size(); i++){
        int next = numbers[i];
        if( next == 1 || next == 4 || next == 7){
            cur_left = arr[next];
            answer.push_back('L');
        }
        else if(next == 3 || next == 6 || next == 9){
            cur_right = arr[next];
            answer.push_back('R');
        }
        else{
        if(abs(arr[next].first - cur_left.first) + abs(arr[next].second - cur_left.second) > abs(arr[next].first - cur_right.first) + abs(arr[next].second - cur_right.second)){
            cur_right = arr[next];
            answer.push_back('R');
        }
        else if(abs(arr[next].first - cur_left.first) + abs(arr[next].second - cur_left.second) == abs(arr[next].first - cur_right.first) + abs(arr[next].second - cur_right.second)){
            if(hand == "right"){
                cur_right = arr[next];
                answer.push_back('R');
            }
            else{
                 cur_left = arr[next];
                 answer.push_back('L');
            }
        }
        else{
            cur_left = arr[next];
            answer.push_back('L');
        }
        }
    }
    return answer;
}
