#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    string a, b;
    cin >> a >> b;

    while(b.length() > 0){
        if(a.length() == b.length())
            break;

        if(b[b.length()-1] == 'B'){
            b.pop_back();
            reverse(b.begin(), b.end());
        }
        else{
            b.pop_back();
        }
    }

    if(a == b){
        cout << 1;
        return 0;
    }
    cout << 0;
}