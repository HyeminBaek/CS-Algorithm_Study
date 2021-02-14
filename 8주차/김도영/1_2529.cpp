#include <iostream>

using namespace std;

int n; 
long long Min = 9e11, Max = 0;
string str;
pair<string, string> ans;
bool visit[10];

void DFS(int start, string num, int idx){
    if(n == idx){
        if(Max < stoll(num)){
            Max = stoll(num);
            ans.first = num;
        }
        if(stoll(num) < Min){
            Min = stoll(num);
            ans.second = num;
        }
        return;
    }

    if(str[idx] == '<'){
        for(int i=start; i<=9; i++){
            if(visit[i] == false){
                visit[i] = true;
                DFS(i, num+to_string(i), idx+1);
                visit[i] = false;
            }
        }
    }
    else{
        for(int i=start; i>=0; i--){
            if(visit[i] == false){
                visit[i] = true;
                DFS(i, num+to_string(i), idx+1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        str += s;
    }

    for(int i=0; i<=9; i++){
        visit[i] = true;
        DFS(i, to_string(i), 0);
        visit[i] = false;
    }
    
    cout << ans.first << "\n" << ans.second;
}