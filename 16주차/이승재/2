//https://www.acmicpc.net/problem/14891
#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
deque<int> que[5];
/*
 * <0> 2 6 <1> 2 6 <2> 2 처럼 회전이 가능한지
 */
void rotate(int idx, int dir){ // 톱니바퀴 번호와 방향. true라면
    int tmp;
    if (dir == -1) { // 왼쪽 회전
        tmp = que[idx].front();
        que[idx].pop_front();
        que[idx].push_back(tmp);
    }
    else{ // 오른쪽 회전
        tmp = que[idx].back();
        que[idx].pop_back();
        que[idx].push_front(tmp);
    }
}
void move_left(int idx, int dir){
    if (idx < 1  or que[idx][2] == que[idx+1][6])
        return;

    move_left(idx - 1, -dir);
    rotate(idx, dir);
}
void move_right(int idx, int dir){
    if (idx > 4 or que[idx-1][2] == que[idx][6])
        return;

    move_right(idx + 1, -dir);
    rotate(idx, dir);
}
void print(){
    for(int i = 1; i < 5; i++){
        for(auto &j : que[i]){
            cout<<j;
        }
        cout <<endl;
    };
}

int main() {
    string str;

    for(int i = 1; i < 5; i ++){
        cin >> str;
        for(char j : str){
            que[i].push_back(j - '0');
        }
    }

    int K, num, way;
    int answer = 0;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> num >> way;
        move_left(num-1, -way);
        move_right(num+1, -way);
        rotate(num, way);

        //print();
    }

    for(int i = 1; i < 5; i++){
        answer += int(pow(2, i-1)) * que[i][0];
    }
    cout<<answer;
    return 0;
}
