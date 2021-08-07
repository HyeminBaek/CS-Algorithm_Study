#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef struct _INFO{
    string lang;
    string job;
    string cnt;
    string food;
    string score;
}INFO;

vector<string> strtok(string str, char delim = ' '){
    vector<string> ret;

    int prev = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == delim){
            string t = str.substr(prev, i-prev);
            if(t != "and"){
                ret.push_back(t);
            }
            prev = i+1;
        }
    }

    if(prev != str.size()){
        ret.push_back(str.substr(prev, str.size()-prev));
    }
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    vector<INFO> person;
    for(int i=0; i<info.size(); i++){
        vector<string> tmp = strtok(info[i]);
        person.push_back({tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]});
    }

    bool check[5];
    for(int i=0; i<query.size(); i++){
        vector<string> tmp = strtok(query[i]);
        memset(check, false, sizeof(check));
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j] == "-")
                check[j] = true;
        }

        int cnt = 0;
        for(int j=0; j<person.size(); j++){
            if((person[j].lang==tmp[0] || check[0]) && (person[j].job == tmp[1] || check[1]) && (person[j].cnt == tmp[2] || check[2]) &&
                        (person[j].food == tmp[3] || check[3]) && (stoi(person[j].score) >= stoi(tmp[4]) || check[4])){
                            cnt++;
                        }
        }

        answer.push_back(cnt);
    }
    return answer;
}


int main(){
    string a[] = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150",
                "cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};

    vector<string> b;
    for(int i=0; i<sizeof(a)/sizeof(string); i++){
        b.push_back(a[i]);
    }
    
    string c[] = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200",
            "cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<string> d;
    for(int i=0; i<sizeof(c)/sizeof(string); i++){
        d.push_back(c[i]);
    }

    solution(b, d);
}