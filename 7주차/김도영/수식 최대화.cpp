#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression){
    long long answer = 0;
    vector<long long> num;
    vector<char> orders;

    string temp = "";
    for(int i=0; i<expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            num.push_back(stoi(temp));
            temp = "";
            orders.push_back(expression[i]);
        }
        else{
            temp += expression[i];
        }
    }
    num.push_back(stoi(temp));
    string e = "*+-";

    do{
        vector<long long> tmp_num = num;
        vector<char> tmp_ord = orders;

        for(int i=0; i<e.size(); i++){
            for(int j=0; j<tmp_ord.size(); j++){
                if(e[i] == tmp_ord[j]){
                    if(tmp_ord[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j+1];
                    else if(tmp_ord[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j+1];
                    else if(tmp_ord[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j+1];

                    tmp_num.erase(tmp_num.begin()+j+1);
                    tmp_ord.erase(tmp_ord.begin()+j);
                    j--;
                }
            }
        }

        answer = max(answer, abs(tmp_num[0]));
    }while(next_permutation(e.begin(), e.end()));

    return answer;
}

int main(){
    cout << solution("100-200*300-500+20");

}