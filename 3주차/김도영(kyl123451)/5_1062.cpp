#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0;
bool alpha[26];
vector<string> v;

void check(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        bool flag = true;

        for(int j=0; j<v[i].length(); j++){
            if(alpha[v[i][j]-'a'] == false){
                flag = false;
                break;
            }
        }

        if(flag == true){
            cnt += 1;
        }
    }

    ans = max(ans, cnt);
}

void DFS(int idx, int cnt){
    if(cnt == k){
        check();
        return;
    }

    for(int i=idx; i<26; i++){
        if(alpha[i] == true) continue;
        alpha[i] = true;
        DFS(i, cnt+1);
        alpha[i] = false;
    }
}

// a, c, i, n, t 
int main(){
    cin >> n >> k;

    if(k < 5){
        cout << 0;
        return 0;
    }
    else if(k == 26){
        cout << n;
        return 0;
    }

    alpha['a' - 'a'] = true;
    alpha['c' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    k -= 5;

    for(int i=0; i<n; i++){
        string str; cin >> str;
        str.erase(str.begin(), str.begin()+4);
        str.erase(str.end()-4, str.end());
        v.push_back(str);
    }

    DFS(0, 0);
    cout << ans;
}