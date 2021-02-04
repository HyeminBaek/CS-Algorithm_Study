#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num, row, col;
pair<int, int> left_hand, right_hand;
string answer = "";

void Insert(bool flag){
    if(flag){
        answer += "L";
        left_hand = {row, col};
    }
    else{
        answer += "R";
        right_hand = {row, col};
    }
}

string solution(vector<int> numbers, string hand) {
    left_hand = {3, 0}; right_hand = {3, 2};

    for(int i=0; i<numbers.size(); i++){
        num = numbers[i] == 0 ? 10 : numbers[i]-1;
        row = num / 3;
        col = num % 3;

        if(col == 0){
            Insert(true);
        }
        else if(col == 2){
            Insert(false);
        }
        else{
            int left_dist = abs(left_hand.first - row) + abs(left_hand.second - col);
            int right_dist = abs(right_hand.first - row) + abs(right_hand.second - col);

            if(left_dist < right_dist){
                Insert(true);
            }
            else if(left_dist > right_dist){
                Insert(false);
            }
            else{
                if(hand == "left"){
                    Insert(true);
                }
                else{
                    Insert(false);
                }
            }
        }
    }
    return answer;
}


int main(){
    int a[] = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    vector<int> b;
    int size = sizeof(a)/sizeof(int);
    for(int i=0; i<size; i++){
        b.push_back(a[i]);
    }
    string h = "right";
    cout << solution(b, h);
}