#include <iostream>

using namespace std;

char stack[1000001];

int main(){
    string str, key; 
    cin >> str >> key;
    int idx = 0;

    for(int i=0; i<str.length(); i++){
        stack[idx++] = str[i];

        if(stack[idx-1] == key[key.length()-1]){
            if (idx - key.length() < 0)
                continue;

            bool flag = true;
            for(int j=0; j<key.length(); j++){
                if(stack[idx-j-1] != key[key.length()-j-1]){
                    flag = false;
                    break;
                }
            }

            if(flag)
                idx -= key.length();
        }
    }
    

    if(idx == 0){
        cout << "FRULA";
        return 0;
    }
    for(int i=0; i<idx; i++){
        cout << stack[i];
    }
    return 0;
}