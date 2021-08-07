#include <iostream>

using namespace std;

class TRIE{
public:
    TRIE* Number[10];
    bool finish;

    TRIE(){
        finish = false;
        fill(Number, Number+10, nullptr);
    }

    ~TRIE(){
        for(int i=0; i<10; i++){
            if(Number[i] != NULL){
                delete(Number[i]);
            }
        }
    }

    void Insert(string s, int idx){
        if(idx == s.length()){
            finish = true;
            return;
        }

        int cur = s[idx] - '0';
        if(Number[cur] == NULL)
            Number[cur] = new TRIE;
        Number[cur]->Insert(s, idx+1);
    }

    bool Call(string s, int idx){
        if(idx == s.length())
            return true;
        if(finish == true)
            return false;

        int cur = s[idx] - '0';
        return Number[cur]->Call(s, idx+1);
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s[10000];
        cin >> n;

        TRIE *root = new TRIE();
        for(int i=0; i<n; i++){
            cin >> s[i];
            root->Insert(s[i], 0);
        }

        bool flag = true;
        for(int i=0; i<n; i++){
            if(flag){
                flag = root->Call(s[i], 0);
                continue;
            }
            break;
        }

        if(flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}