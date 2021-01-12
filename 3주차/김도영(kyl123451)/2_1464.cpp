//분할정복

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main(){
    string str, temp;
    cin >> str;

    for(int i=1; i<str.length(); i++){
        if(str[i] > str[i-1]){
            temp = str[i];
            str.erase(i,1);
            str = temp + str;
        }
    }

    cout << str;
}